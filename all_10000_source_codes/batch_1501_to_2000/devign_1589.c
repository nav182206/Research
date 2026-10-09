/* 
 * Benchmark Sample ID : devign_1589
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3caffb7d80f20c66d7d582ca3d23f80ad373ba0a
 */

static int common_end(AVCodecContext *avctx){

    FFV1Context *s = avctx->priv_data;

    int i;



    for(i=0; i<s->plane_count; i++){

        PlaneContext *p= &s->plane[i];



        av_freep(&p->state);


    }



    return 0;

}
