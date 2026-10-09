/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_15
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2df0c32ea12ddfa72ba88309812bfb13b674130f
 */

av_cold void ff_af_queue_init(AVCodecContext *avctx, AudioFrameQueue *afq)

{

    afq->avctx             = avctx;

    afq->next_pts          = AV_NOPTS_VALUE;

    afq->remaining_delay   = avctx->delay;

    afq->remaining_samples = avctx->delay;

    afq->frame_queue       = NULL;

}
