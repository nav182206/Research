/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9432
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8cdd2e0abbf593a38a146d8dfc998754cefbc27a
 */

int tpm_register_model(enum TpmModel model)

{

    int i;



    for (i = 0; i < TPM_MAX_MODELS; i++) {

        if (tpm_models[i] == -1) {

            tpm_models[i] = model;

            return 0;

        }

    }

    error_report("Could not register TPM model");

    return 1;

}
