/* 
 * Benchmark Sample ID : devign_9651
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c18ad9a54b75495ce61e8b28d353f8eec51768fc
 */

void ppc_hash64_stop_access(uint64_t token)

{

    if (kvmppc_kern_htab) {

        kvmppc_hash64_free_pteg(token);

    }

}
