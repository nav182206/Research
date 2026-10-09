/* 
 * Benchmark Sample ID : devign_4899
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=08b277ac46da8b02e50cec455eca7cb2d12ffcf0
 */

static bool version_is_5(void *opaque, int version_id)

{

    return version_id == 5;

}
