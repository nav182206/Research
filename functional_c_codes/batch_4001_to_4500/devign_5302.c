/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5302
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=80ca19f766aea8f4724aac1b3faa772d25163c8a
 */

static int ipvideo_decode_block_opcode_0x3(IpvideoContext *s)

{

    unsigned char B;

    int x, y;



    /* copy 8x8 block from current frame from an up/left block */



    /* need 1 more byte for motion */

    CHECK_STREAM_PTR(1);

    B = *s->stream_ptr++;



    if (B < 56) {

        x = -(8 + (B % 7));

        y = -(B / 7);

    } else {

        x = -(-14 + ((B - 56) % 29));

        y = -(  8 + ((B - 56) / 29));

    }



    debug_interplay ("    motion byte = %d, (x, y) = (%d, %d)\n", B, x, y);

    return copy_from(s, &s->current_frame, x, y);

}
