/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2697
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=73d60fa5fae60c8e07e1f295d8c7fd5d04320160
 */

static void set_sensor_type(IPMIBmcSim *ibs,

                               uint8_t *cmd, unsigned int cmd_len,

                               uint8_t *rsp, unsigned int *rsp_len,

                               unsigned int max_rsp_len)

{

    IPMISensor *sens;





    IPMI_CHECK_CMD_LEN(5);

    if ((cmd[2] > MAX_SENSORS) ||

            !IPMI_SENSOR_GET_PRESENT(ibs->sensors + cmd[2])) {

        rsp[2] = IPMI_CC_REQ_ENTRY_NOT_PRESENT;

        return;

    }

    sens = ibs->sensors + cmd[2];

    sens->sensor_type = cmd[3];

    sens->evt_reading_type_code = cmd[4] & 0x7f;

}
