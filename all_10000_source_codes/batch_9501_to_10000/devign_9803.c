/* 
 * Benchmark Sample ID : devign_9803
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ca00a7e809a4b9c9fb146403d278964b88d16b85
 */

static int decode_mime_header(AMRWBContext *ctx, const uint8_t *buf)

{

    /* Decode frame header (1st octet) */

    ctx->fr_cur_mode  = buf[0] >> 3 & 0x0F;

    ctx->fr_quality   = (buf[0] & 0x4) != 0x4;



    return 1;

}
