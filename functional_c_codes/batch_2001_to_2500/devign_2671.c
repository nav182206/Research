/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2671
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=92dcc234ec1f266fb5d59bed77d66320c2c75965
 */

static void tpm_passthrough_cancel_cmd(TPMBackend *tb)

{

    /* cancelling an ongoing command is known not to work with some TPMs */

}
