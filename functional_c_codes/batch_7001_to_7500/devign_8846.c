/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8846
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a83000f5e3fac30a7f213af1ba6a8f827622854d
 */

void spapr_iommu_init(void)

{

    QLIST_INIT(&spapr_tce_tables);



    /* hcall-tce */

    spapr_register_hypercall(H_PUT_TCE, h_put_tce);

}
