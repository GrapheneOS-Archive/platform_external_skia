/*
 * Copyright 2021 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef skgpu_Caps_DEFINED
#define skgpu_Caps_DEFINED

#include "experimental/graphite/src/ResourceTypes.h"
#include "include/core/SkImageInfo.h"
#include "include/core/SkRefCnt.h"

namespace SkSL {
struct ShaderCaps;
}

namespace skgpu {

class TextureInfo;

class Caps : public SkRefCnt {
public:
    ~Caps() override;

    const SkSL::ShaderCaps* shaderCaps() const { return fShaderCaps.get(); }

    virtual TextureInfo getDefaultSampledTextureInfo(SkColorType,
                                                     uint32_t levelCount,
                                                     Protected,
                                                     Renderable) const = 0;

    virtual TextureInfo getDefaultMSAATextureInfo(SkColorType,
                                                  uint32_t sampleCount,
                                                  Protected) const = 0;

    virtual TextureInfo getDefaultDepthStencilTextureInfo(DepthStencilType,
                                                          uint32_t sampleCount,
                                                          Protected) const = 0;

protected:
    Caps();

    std::unique_ptr<SkSL::ShaderCaps> fShaderCaps;

private:
};

} // namespace skgpu

#endif // skgpu_Caps_DEFINED
