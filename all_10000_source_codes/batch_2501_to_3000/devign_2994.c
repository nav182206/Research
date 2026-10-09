/* 
 * Benchmark Sample ID : devign_2994
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d7651f150d61936344c4fab45eaeb0716c606af2
 */

bool postcopy_ram_supported_by_host(void)

{

    error_report("%s: No OS support", __func__);

    return false;

}
