/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6219
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=330deb75923675224fb9aed311d3d6ce3ec52420
 */

static void free_duplicate_context(MpegEncContext *s){

    if(s==NULL) return;



    av_freep(&s->allocated_edge_emu_buffer); s->edge_emu_buffer= NULL;

    av_freep(&s->me.scratchpad);

    s->me.temp=

    s->rd_scratchpad=

    s->b_scratchpad=

    s->obmc_scratchpad= NULL;



    av_freep(&s->dct_error_sum);

    av_freep(&s->me.map);

    av_freep(&s->me.score_map);

    av_freep(&s->blocks);

    av_freep(&s->ac_val_base);

    s->block= NULL;

}
