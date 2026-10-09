/* 
 * Benchmark Sample ID : devign_131
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=220b24c7c97dc033ceab1510549f66d0e7b52ef1
 */

static void parse_context_init(SchroParseUnitContext *parse_ctx,

                               const uint8_t *buf, int buf_size)

{

    parse_ctx->buf           = buf;

    parse_ctx->buf_size      = buf_size;

}
