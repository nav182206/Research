/* 
 * Benchmark Sample ID : devign_5304
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=80ca19f766aea8f4724aac1b3faa772d25163c8a
 */

static int ipvideo_decode_block_opcode_0xE(IpvideoContext *s)

{

    int y;

    unsigned char pix;



    /* 1-color encoding: the whole block is 1 solid color */

    CHECK_STREAM_PTR(1);

    pix = *s->stream_ptr++;



    for (y = 0; y < 8; y++) {

        memset(s->pixel_ptr, pix, 8);

        s->pixel_ptr += s->stride;

    }



    /* report success */

    return 0;

}
