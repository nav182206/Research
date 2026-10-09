/* 
 * Benchmark Sample ID : devign_4948
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=80ca19f766aea8f4724aac1b3faa772d25163c8a
 */

static int ipvideo_decode_block_opcode_0xF(IpvideoContext *s)

{

    int x, y;

    unsigned char sample[2];



    /* dithered encoding */

    CHECK_STREAM_PTR(2);

    sample[0] = *s->stream_ptr++;

    sample[1] = *s->stream_ptr++;



    for (y = 0; y < 8; y++) {

        for (x = 0; x < 8; x += 2) {

            *s->pixel_ptr++ = sample[  y & 1 ];

            *s->pixel_ptr++ = sample[!(y & 1)];

        }

        s->pixel_ptr += s->line_inc;

    }



    /* report success */

    return 0;

}
