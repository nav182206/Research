/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9203
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d8245c3bcdd162891825a52cf55e4e8173d85a18
 */

static av_cold int cinvideo_decode_end(AVCodecContext *avctx)

{

    CinVideoContext *cin = avctx->priv_data;

    int i;



    if (cin->frame.data[0])

        avctx->release_buffer(avctx, &cin->frame);



    for (i = 0; i < 3; ++i)

        av_free(cin->bitmap_table[i]);



    return 0;

}
