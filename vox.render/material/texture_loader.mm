//  Copyright (c) 2022 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include <Metal/Metal.h>
#include "texture_loader.h"
#include "cpp_mtl_device.h"
#include <string>
#include <array>

using namespace MTL;

namespace vox {
TextureLoader::TextureLoader(MTL::Device &device)
: _objCObj([[MTKTextureLoader alloc] initWithDevice:device.objCObj()]), _device(&device) {
    // Member initialization only
}


TextureLoader::~TextureLoader() {
    _objCObj = nil;
}

NSDictionary *textureLoaderDictionary(const TextureLoaderOptions &options) {
    NSDictionary *textureLoaderOptions =
    @{
        MTKTextureLoaderOptionTextureUsage: @(options.usage),
        MTKTextureLoaderOptionTextureStorageMode: @(options.storageMode),
    };
    
    return [textureLoaderOptions copyWithZone:nil];
}

MTL::TexturePtr TextureLoader::makeTexture(const char *name,
                                           float screenScaleFactor,
                                           const TextureLoaderOptions &options,
                                           CFErrorRef *error) {
    NSString *nsname = [[NSString alloc] initWithUTF8String:name];
    NSError *nserror;
    
    id <MTLTexture> objCTexture = [_objCObj newTextureWithName:nsname
                                                   scaleFactor:1.0
                                                        bundle:nil
                                                       options:textureLoaderDictionary(options)
                                                         error:&nserror];
    
    if (!objCTexture) {
        if (error) {
            *error = (__bridge CFErrorRef) nserror;
        }
        return nullptr;
    }
    
    return std::make_shared<Texture>(objCTexture, *_device);
}

MTL::TexturePtr TextureLoader::makeTexture(const char *URLString,
                                           const TextureLoaderOptions &options,
                                           CFErrorRef *error) {
    NSString *nsURLString = [[NSString alloc] initWithUTF8String:URLString];
    NSURL *URL = [[NSURL alloc] initWithString:nsURLString];
    NSError *nserror;
    
    id <MTLTexture> objCTexture = [_objCObj newTextureWithContentsOfURL:URL
                                                                options:textureLoaderDictionary(options)
                                                                  error:&nserror];
    
    if (!objCTexture) {
        if (error) {
            *error = (__bridge CFErrorRef) nserror;
        }
        return nullptr;
    }
    
    return std::make_shared<Texture>(objCTexture, *_device);
}

TexturePtr TextureLoader::loadCubeTexture(const std::string &path,
                                          const std::array<std::string, 6> &imageName,
                                          bool isTopLeft) {
    NSString *pathName = [[NSString alloc] initWithUTF8String:path.c_str()];
    NSString *textureName1 = [[NSString alloc] initWithUTF8String:imageName[0].c_str()];
    NSString *textureName2 = [[NSString alloc] initWithUTF8String:imageName[1].c_str()];
    NSString *textureName3 = [[NSString alloc] initWithUTF8String:imageName[2].c_str()];
    NSString *textureName4 = [[NSString alloc] initWithUTF8String:imageName[3].c_str()];
    NSString *textureName5 = [[NSString alloc] initWithUTF8String:imageName[4].c_str()];
    NSString *textureName6 = [[NSString alloc] initWithUTF8String:imageName[5].c_str()];
    
    NSMutableArray<NSString *> *imageNames = [[NSMutableArray alloc] init];
    [imageNames addObject:textureName1];
    [imageNames addObject:textureName2];
    [imageNames addObject:textureName3];
    [imageNames addObject:textureName4];
    [imageNames addObject:textureName5];
    [imageNames addObject:textureName6];
    
    MDLTexture *mdlTexture = [MDLTexture textureCubeWithImagesNamed:imageNames bundle:[NSBundle bundleWithPath:pathName]];
    MTKTextureLoaderOrigin origin = MTKTextureLoaderOriginTopLeft;
    if (!isTopLeft) {
        origin = MTKTextureLoaderOriginBottomLeft;
    }
    
    NSDictionary < MTKTextureLoaderOption, id > *options = @{
        MTKTextureLoaderOptionOrigin: origin,
        MTKTextureLoaderOptionGenerateMipmaps: [NSNumber numberWithBool:FALSE],
        MTKTextureLoaderOptionTextureUsage: [NSNumber numberWithUnsignedLong:MTLTextureUsageShaderRead]
    };
    NSError *error = nil;
    id <MTLTexture> mtlTexture = [_objCObj newTextureWithMDLTexture:mdlTexture options:options error:&error];
    if (error != nil) {
        NSLog(@"Error: failed to create MTLTexture: %@", error);
    }
    
    return std::make_shared<Texture>(mtlTexture, *_device);
}

MTL::Texture TextureLoader::loadTexture(const std::string &path, const std::string &imageName, bool isTopLeft) {
    NSString *pathName = [[NSString alloc] initWithUTF8String:path.c_str()];
    NSString *textureName = [[NSString alloc] initWithUTF8String:imageName.c_str()];
    NSURL *url = [[NSBundle bundleWithPath:pathName] URLForResource:textureName withExtension:nil];
    
    MTKTextureLoaderOrigin origin = MTKTextureLoaderOriginTopLeft;
    if (!isTopLeft) {
        origin = MTKTextureLoaderOriginBottomLeft;
    }
    
    NSDictionary < MTKTextureLoaderOption, id > *options = @{
        MTKTextureLoaderOptionOrigin: origin,
        MTKTextureLoaderOptionGenerateMipmaps: [NSNumber numberWithBool:TRUE]
    };
    
    NSError *error = nil;
    id <MTLTexture> texture = [_objCObj newTextureWithContentsOfURL:url
                                                            options:options error:&error];
    if (error != nil) {
        NSLog(@"Error: failed to create MTLTexture: %@", error);
    }
    
    return Texture(texture, *_device);
}

}
