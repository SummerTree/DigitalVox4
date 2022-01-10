/*
 See LICENSE folder for this sample’s licensing information.
 
 Abstract:
 Validation code for C++ Metal pixel format enum values
 */

#include "CPPMetalPixelFormat.hpp"
#include "CPPMetalImplementation.hpp"
#include "CPPMetalInternalMacros.h"
#include <Metal/Metal.h>

using namespace MTL;

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatInvalid);

/* Normal 8 bit formats */

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatA8Unorm);

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatR8Unorm);

#if TARGET_OS_IPHONE
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatR8Unorm_sRGB );
#endif

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatR8Snorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatR8Uint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatR8Sint);

/* Normal 16 bit formats */

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatR16Unorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatR16Snorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatR16Uint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatR16Sint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatR16Float);

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRG8Unorm);

#if TARGET_OS_IPHONE
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatRG8Unorm_sRGB );
#endif

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRG8Snorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRG8Uint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRG8Sint);

/* Normal 32 bit formats */

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatR32Uint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatR32Sint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatR32Float);

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRG16Unorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRG16Snorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRG16Uint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRG16Sint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRG16Float);

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGBA8Unorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGBA8Unorm_sRGB);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGBA8Snorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGBA8Uint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGBA8Sint);

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBGRA8Unorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBGRA8Unorm_sRGB);

/* Packed 32 bit formats */

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGB10A2Unorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGB10A2Uint);

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRG11B10Float);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGB9E5Float);

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBGR10A2Unorm);

#if TARGET_OS_IPHONE
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatBGR10_XR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatBGR10_XR_sRGB );
#endif
/* Normal 64 bit formats */

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRG32Uint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRG32Sint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRG32Float);

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGBA16Unorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGBA16Snorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGBA16Uint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGBA16Sint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGBA16Float);

#if TARGET_OS_IPHONE
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatBGRA10_XR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatBGRA10_XR_sRGB );
#endif
/* Normal 128 bit formats */

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGBA32Uint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGBA32Sint);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatRGBA32Float);

/* Compressed formats. */

#if TARGET_OS_OSX
/* S3TC/DXT */
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBC1_RGBA);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBC1_RGBA_sRGB);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBC2_RGBA);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBC2_RGBA_sRGB);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBC3_RGBA);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBC3_RGBA_sRGB);

/* RGTC */
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBC4_RUnorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBC4_RSnorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBC5_RGUnorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBC5_RGSnorm);

/* BPTC */
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBC6H_RGBFloat);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBC6H_RGBUfloat);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBC7_RGBAUnorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBC7_RGBAUnorm_sRGB);
#endif

#if TARGET_OS_IPHONE
/* PVRTC */
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatPVRTC_RGB_2BPP );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatPVRTC_RGB_2BPP_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatPVRTC_RGB_4BPP );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatPVRTC_RGB_4BPP_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatPVRTC_RGBA_2BPP );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatPVRTC_RGBA_2BPP_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatPVRTC_RGBA_4BPP );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatPVRTC_RGBA_4BPP_sRGB );

/* ETC2 */
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatEAC_R11Unorm );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatEAC_R11Snorm );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatEAC_RG11Unorm );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatEAC_RG11Snorm );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatEAC_RGBA8 );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatEAC_RGBA8_sRGB );

CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatETC2_RGB8 );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatETC2_RGB8_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatETC2_RGB8A1 );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatETC2_RGB8A1_sRGB );

/* ASTC */
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_4x4_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_5x4_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_5x5_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_6x5_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_6x6_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_8x5_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_8x6_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_8x8_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_10x5_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_10x6_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_10x8_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_10x10_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_12x10_sRGB );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_12x12_sRGB );

CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_4x4_LDR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_5x4_LDR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_5x5_LDR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_6x5_LDR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_6x6_LDR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_8x5_LDR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_8x6_LDR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_8x8_LDR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_10x5_LDR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_10x6_LDR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_10x8_LDR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_10x10_LDR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_12x10_LDR );
CPP_METAL_VALIDATE_ENUM_ALIAS( PixelFormatASTC_12x12_LDR );
#endif /* TARGET_OS_IPHONE */

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatGBGR422);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatBGRG422);

/* Depth */

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatDepth16Unorm);
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatDepth32Float);

/* Stencil */

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatStencil8);

/* Depth Stencil */
#if TARGET_OS_OSX
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatDepth24Unorm_Stencil8);
#endif

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatDepth32Float_Stencil8);

CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatX32_Stencil8);

#if TARGET_OS_OSX
CPP_METAL_VALIDATE_ENUM_ALIAS(PixelFormatX24_Stencil8);
#endif


