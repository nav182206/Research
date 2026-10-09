/* 
 * Benchmark Sample ID : devign_1716
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4f298a4b2957b7833bc607c951ca27c458d98d88
 */

static void set_bmc_global_enables(IPMIBmcSim *ibs,

                                   uint8_t *cmd, unsigned int cmd_len,

                                   uint8_t *rsp, unsigned int *rsp_len,

                                   unsigned int max_rsp_len)

{

    IPMI_CHECK_CMD_LEN(3);

    set_global_enables(ibs, cmd[2]);

}
