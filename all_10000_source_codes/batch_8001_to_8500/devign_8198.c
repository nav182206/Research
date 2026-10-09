/* 
 * Benchmark Sample ID : devign_8198
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=142e0950cfaf023a81112dc3cdfa799d769886a4
 */

bool hpet_find(void)

{

    return object_resolve_path_type("", TYPE_HPET, NULL);

}
