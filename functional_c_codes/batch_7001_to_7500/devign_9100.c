/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9100
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a83000f5e3fac30a7f213af1ba6a8f827622854d
 */

void spapr_tce_free(sPAPRTCETable *tcet)

{

    QLIST_REMOVE(tcet, list);



    if (!kvm_enabled() ||

        (kvmppc_remove_spapr_tce(tcet->table, tcet->fd,

                                 tcet->window_size) != 0)) {

        g_free(tcet->table);

    }



    g_free(tcet);

}
