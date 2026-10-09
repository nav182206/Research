/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5591
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a9a72aeefbd3ef8bcbbeeccaf174ee10db2978ac
 */

int tpm_register_driver(const TPMDriverOps *tdo)

{

    int i;



    for (i = 0; i < TPM_MAX_DRIVERS; i++) {

        if (!be_drivers[i]) {

            be_drivers[i] = tdo;

            return 0;

        }

    }

    error_report("Could not register TPM driver");

    return 1;

}
