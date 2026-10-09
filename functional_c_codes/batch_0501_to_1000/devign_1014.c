/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1014
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=715c54071a43ab978dc12b9da22a5016203ed284
 */

static int spapr_check_htab_fd(sPAPRMachineState *spapr)

{

    int rc = 0;



    if (spapr->htab_fd_stale) {

        close(spapr->htab_fd);

        spapr->htab_fd = kvmppc_get_htab_fd(false);

        if (spapr->htab_fd < 0) {

            error_report("Unable to open fd for reading hash table from KVM: "

                         "%s", strerror(errno));

            rc = -1;

        }

        spapr->htab_fd_stale = false;

    }



    return rc;

}
