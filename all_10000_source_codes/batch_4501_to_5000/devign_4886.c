/* 
 * Benchmark Sample ID : devign_4886
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=307b7715d0256c95444cada36a02882e46bada2f
 */

static void set_signalled(sPAPRDRConnector *drc)

{

    drc->signalled = true;

}
