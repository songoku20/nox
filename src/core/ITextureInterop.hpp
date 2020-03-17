#pragma once
#include <libavutil/hwcontext.h>

#include <memory>

#include "Texture.hpp"

namespace nox::core
{
class ITextureInterop
{
   public:
    virtual bool IsValid() = 0;
    virtual void Process(AVHWFramesContext* hwFramesContext) = 0;
    virtual std::shared_ptr<Texture> GetTexture() = 0;
};
} // namespace nox::core