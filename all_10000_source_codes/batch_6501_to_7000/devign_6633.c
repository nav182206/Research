/* 
 * Benchmark Sample ID : devign_6633
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b9dd906d18f4cd801ceedd20d800a7e53074be9
 */

static int decode_2(SANMVideoContext *ctx)

{

    int cx, cy, ret;



    for (cy = 0; cy != ctx->aligned_height; cy += 8) {

        for (cx = 0; cx != ctx->aligned_width; cx += 8) {

            if (ret = codec2subblock(ctx, cx, cy, 8))

                return ret;

        }

    }



    return 0;

}
