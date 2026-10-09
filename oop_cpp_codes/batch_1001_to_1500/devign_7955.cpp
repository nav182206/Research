/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7955
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4f298a4b2957b7833bc607c951ca27c458d98d88
 */

static void rearm_sensor_evts(IPMIBmcSim *ibs,

                              uint8_t *cmd, unsigned int cmd_len,

                              uint8_t *rsp, unsigned int *rsp_len,

                              unsigned int max_rsp_len)

{

    IPMISensor *sens;



    IPMI_CHECK_CMD_LEN(4);

    if ((cmd[2] >= MAX_SENSORS) ||

        !IPMI_SENSOR_GET_PRESENT(ibs->sensors + cmd[2])) {

        rsp[2] = IPMI_CC_REQ_ENTRY_NOT_PRESENT;

        return;

    }

    sens = ibs->sensors + cmd[2];



    if ((cmd[3] & 0x80) == 0) {

        /* Just clear everything */

        sens->states = 0;

        return;

    }

}
