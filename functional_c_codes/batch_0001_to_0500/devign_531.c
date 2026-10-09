/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_531
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=dc9f52602f6493b33d1ac0d729ffb188e6a676fa
 */

static int decode_end(AVCodecContext *avctx)

{

    H264Context *h = avctx->priv_data;

    MpegEncContext *s = &h->s;

    


    free_tables(h); //FIXME cleanup init stuff perhaps

    MPV_common_end(s);



//    memset(h, 0, sizeof(H264Context));

        

    return 0;

}
