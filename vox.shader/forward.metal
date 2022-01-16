//
//  forward.metal
//  vox.shader
//
//  Created by 杨丰 on 2022/1/16.
//

#include <metal_stdlib>

using namespace metal;

// Include header shared between this Metal shader code and C code executing Metal API commands
#include "shader_types.h"

// Include header shared between all Metal shader code files
#include "shader_common.h"

// Per-vertex inputs fed by vertex buffer laid out with MTLVertexDescriptor in Metal API
struct DescriptorDefinedVertex {
    float3 position  [[attribute(VertexAttributePosition)]];
    float2 tex_coord [[attribute(VertexAttributeTexcoord)]];
    half3 normal     [[attribute(VertexAttributeNormal)]];
    half3 tangent    [[attribute(VertexAttributeTangent)]];
    half3 bitangent  [[attribute(VertexAttributeBitangent)]];
};

// Vertex shader outputs and per-fragment inputs.  Includes clip-space position and vertex outputs
// interpolated by rasterizer and fed to each fragment generated by clip-space primitives.
struct ColorInOut {
    float4 position [[position]];
    float2 tex_coord;
    float2 shadow_uv;
    half   shadow_depth;
    float3 eye_position;
    half3  tangent;
    half3  bitangent;
    half3  normal;
};

vertex ColorInOut forward_vertex(DescriptorDefinedVertex in    [[ stage_in ]],
                                 constant FrameData &frameData [[ buffer(BufferIndexFrameData) ]]) {
    ColorInOut out;
    
    float4 model_position = float4(in.position, 1.0);
    // Make position a float4 to perform 4x4 matrix math on it
    float4 eye_position = frameData.temple_modelview_matrix * model_position;
    out.position = frameData.projection_matrix * eye_position;
    out.tex_coord = float2(in.tex_coord.x, 1-in.tex_coord.y);
    
#if USE_EYE_DEPTH
    out.eye_position = eye_position.xyz;
#endif
    
    // Rotate tangents, bitangents, and normals by the normal matrix
    half3x3 normalMatrix = half3x3(frameData.temple_normal_matrix);
    
    float3 shadow_coord = (frameData.shadow_mvp_xform_matrix * model_position ).xyz;
    out.shadow_uv = shadow_coord.xy;
    out.shadow_depth = half(shadow_coord.z);
    
    // Calculate tangent, bitangent and normal in eye's space
    out.tangent = normalize(normalMatrix * in.tangent);
    out.bitangent = -normalize(normalMatrix * in.bitangent);
    out.normal = normalize(normalMatrix * in.normal);
    
    return out;
}

fragment half4 forward_fragment(ColorInOut               in           [[ stage_in ]],
                                constant FrameData & frameData    [[ buffer(BufferIndexFrameData) ]],
                                texture2d<half>          baseColorMap [[ texture(TextureIndexBaseColor) ]],
                                texture2d<half>          normalMap    [[ texture(TextureIndexNormal) ]],
                                texture2d<half>          specularMap  [[ texture(TextureIndexSpecular) ]],
                                depth2d<float>           shadowMap    [[ texture(TextureIndexShadow) ]]) {
    constexpr sampler linearSampler(mip_filter::linear,
                                    mag_filter::linear,
                                    min_filter::linear);
    
    half4 base_color_sample = baseColorMap.sample(linearSampler, in.tex_coord.xy);
    half specular_contrib = specularMap.sample(linearSampler, in.tex_coord.xy).r;
    
    // Store shadow with albedo in unused fourth channel
    return half4(base_color_sample.xyz, specular_contrib);
}
