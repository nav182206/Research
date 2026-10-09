/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7339
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3992526b3c43278945d00fac6e2ba5cb8f810ef3
 */

static void vc1_loop_filter_iblk(MpegEncContext *s, int pq)

{

    int i, j;

    if(!s->first_slice_line)

        s->dsp.vc1_loop_filter(s->dest[0], 1, s->linesize, 16, pq);

    s->dsp.vc1_loop_filter(s->dest[0] + 8*s->linesize, 1, s->linesize, 16, pq);

    for(i = !s->mb_x*8; i < 16; i += 8)

        s->dsp.vc1_loop_filter(s->dest[0] + i, s->linesize, 1, 16, pq);

    for(j = 0; j < 2; j++){

        if(!s->first_slice_line)

            s->dsp.vc1_loop_filter(s->dest[j+1], 1, s->uvlinesize, 8, pq);

        if(s->mb_x)

            s->dsp.vc1_loop_filter(s->dest[j+1], s->uvlinesize, 1, 8, pq);

    }

}
