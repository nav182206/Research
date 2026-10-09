/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9525
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=92dcc234ec1f266fb5d59bed77d66320c2c75965
 */

static void tpm_passthrough_worker_thread(gpointer data,

                                          gpointer user_data)

{

    TPMPassthruThreadParams *thr_parms = user_data;

    TPMPassthruState *tpm_pt = thr_parms->tb->s.tpm_pt;

    TPMBackendCmd cmd = (TPMBackendCmd)data;



    DPRINTF("tpm_passthrough: processing command type %d\n", cmd);



    switch (cmd) {

    case TPM_BACKEND_CMD_PROCESS_CMD:

        tpm_passthrough_unix_transfer(tpm_pt->tpm_fd,

                                      thr_parms->tpm_state->locty_data);



        thr_parms->recv_data_callback(thr_parms->tpm_state,

                                      thr_parms->tpm_state->locty_number);

        break;

    case TPM_BACKEND_CMD_INIT:

    case TPM_BACKEND_CMD_END:

    case TPM_BACKEND_CMD_TPM_RESET:

        /* nothing to do */

        break;

    }

}
