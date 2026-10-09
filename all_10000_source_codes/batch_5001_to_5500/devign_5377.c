/* 
 * Benchmark Sample ID : devign_5377
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2db59a76c421cdd1039d10e32a9798952d3ff5ba
 */

static void reset_used_window(DisasContext *dc)

{

    dc->used_window = 0;

}
