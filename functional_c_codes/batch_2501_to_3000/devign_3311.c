/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3311
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d6b64b2b606fe0fe5f2208e84ff7a28445de666a
 */

void tcg_prologue_init(TCGContext *s)
{
    /* init global prologue and epilogue */
    s->code_buf = s->code_gen_prologue;
    s->code_ptr = s->code_buf;
    tcg_target_qemu_prologue(s);
    flush_icache_range((tcg_target_ulong)s->code_buf,
                       (tcg_target_ulong)s->code_ptr);
