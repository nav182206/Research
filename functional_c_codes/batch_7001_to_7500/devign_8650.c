/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8650
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d565fef1b83b6c5f8afb32229260b79f67c68109
 */

int av_vdpau_bind_context(AVCodecContext *avctx, VdpDevice device,

                          VdpGetProcAddress *get_proc, unsigned flags)

{

    VDPAUHWContext *hwctx;



    if (flags != 0)

        return AVERROR(EINVAL);



    if (av_reallocp(&avctx->hwaccel_context, sizeof(*hwctx)))

        return AVERROR(ENOMEM);



    hwctx = avctx->hwaccel_context;



    memset(hwctx, 0, sizeof(*hwctx));

    hwctx->context.decoder  = VDP_INVALID_HANDLE;

    hwctx->device           = device;

    hwctx->get_proc_address = get_proc;

    hwctx->reset            = 1;

    return 0;

}
