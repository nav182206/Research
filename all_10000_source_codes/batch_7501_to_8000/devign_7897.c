/* 
 * Benchmark Sample ID : devign_7897
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5b8009f4c80d8fd96523c8c163441ad4011ad472
 */

static inline void range_dec_normalize(APEContext *ctx)

{

    while (ctx->rc.range <= BOTTOM_VALUE) {

        ctx->rc.buffer <<= 8;

        if(ctx->ptr < ctx->data_end)

            ctx->rc.buffer += *ctx->ptr;

        ctx->ptr++;

        ctx->rc.low    = (ctx->rc.low << 8)    | ((ctx->rc.buffer >> 1) & 0xFF);

        ctx->rc.range  <<= 8;

    }

}
