/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6208
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e3cffe6fad29e07d401eabb913a6d88501d5c143
 */

static inline void gen_check_tlb_flush(DisasContext *ctx) { }
