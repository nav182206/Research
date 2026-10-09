/* 
 * Benchmark Sample ID : devign_5410
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=35f9304d925a5423c51bd2c83a81fa3cc2b6e680
 */

static inline int lock_hpte(void *hpte, target_ulong bits)

{

    uint64_t pteh;



    pteh = ldq_p(hpte);



    /* We're protected by qemu's global lock here */

    if (pteh & bits) {

        return 0;

    }

    stq_p(hpte, pteh | HPTE_V_HVLOCK);

    return 1;

}
