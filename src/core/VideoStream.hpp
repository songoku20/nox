#pragma once
#include "IStream.hpp"
#include "ITextureMapper.hpp"

namespace nox::core
{
class VideoStream : public IStream
{
   public:
    VideoStream(AVStream*& stream);
    ~VideoStream();

    float GetDuration() override;
    float GetPosition() override;
    StreamType GetType() override;

   protected:
    static AVPixelFormat GetHardwareFormat(AVCodecContext* ctx,
                                           const AVPixelFormat* pix_fmts);
    bool InitializeHardwareDevice();
    // Derived from IStream
    void Process(AVPacket& pkt) override;

    // Basic AVCodec members
    AVCodec* m_codec;
    AVCodecContext* m_codecCtx;

    // Hardware decoding
    AVBufferRef* m_hwDeviceCtx;
    AVHWDeviceType m_hwDeviceType;
    AVPixelFormat m_hwPixelFormat;
    bool m_useHwFrames;
    bool m_useHwDevice;

    bool m_useHwDecode;
    std::unique_ptr<ITextureMapper> m_texInterop;
};
} // namespace nox::core