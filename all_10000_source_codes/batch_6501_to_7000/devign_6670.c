/* 
 * Benchmark Sample ID : devign_6670
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=179a2f04eb2bd6df7221883a92dc4e00cf94394b
 */

void checkasm_check_vf_threshold(void)

{

    check_threshold_8();

    report("threshold8");

}
