/* 
 * Benchmark Sample ID : devign_3057
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d38c173dfb4bbee19ec341202c6c79bb0aa2cdad
 */

static void yae_clear(ATempoContext *atempo)

{

    atempo->size = 0;

    atempo->head = 0;

    atempo->tail = 0;



    atempo->drift = 0;

    atempo->nfrag = 0;

    atempo->state = YAE_LOAD_FRAGMENT;



    atempo->position[0] = 0;

    atempo->position[1] = 0;



    atempo->frag[0].position[0] = 0;

    atempo->frag[0].position[1] = 0;

    atempo->frag[0].nsamples    = 0;



    atempo->frag[1].position[0] = 0;

    atempo->frag[1].position[1] = 0;

    atempo->frag[1].nsamples    = 0;



    // shift left position of 1st fragment by half a window

    // so that no re-normalization would be required for

    // the left half of the 1st fragment:

    atempo->frag[0].position[0] = -(int64_t)(atempo->window / 2);

    atempo->frag[0].position[1] = -(int64_t)(atempo->window / 2);



    av_frame_free(&atempo->dst_buffer);

    atempo->dst     = NULL;

    atempo->dst_end = NULL;



    atempo->request_fulfilled = 0;

    atempo->nsamples_in       = 0;

    atempo->nsamples_out      = 0;

}
