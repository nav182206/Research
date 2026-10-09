/* 
 * Benchmark Sample ID : devign_1394
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f1c52354e5bdab6983d13a4c174759c585e834b3
 */

static bool release_pending(sPAPRDRConnector *drc)

{

    return drc->awaiting_release;

}
