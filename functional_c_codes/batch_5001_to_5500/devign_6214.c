/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6214
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=97f8c6e14753b94c1f6a96fe354a125bbfdea2cb
 */

int ff_thread_can_start_frame(AVCodecContext *avctx)

{

    PerThreadContext *p = avctx->thread_opaque;

    if ((avctx->active_thread_type&FF_THREAD_FRAME) && p->state != STATE_SETTING_UP &&

        (avctx->codec->update_thread_context || (!avctx->thread_safe_callbacks &&

                avctx->get_buffer != avcodec_default_get_buffer))) {

        return 0;

    }

    return 1;

}
