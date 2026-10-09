/* 
 * Benchmark Sample ID : devign_6115
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2770c90d432b571cab718e28f838097f0b2201ec
 */

int scsi_convert_sense(uint8_t *in_buf, int in_len,

                       uint8_t *buf, int len, bool fixed)

{

    SCSISense sense;

    bool fixed_in;



    fixed_in = (in_buf[0] & 2) == 0;

    if (in_len && fixed == fixed_in) {

        memcpy(buf, in_buf, MIN(len, in_len));

        return MIN(len, in_len);

    }



    if (in_len == 0) {

        sense = SENSE_CODE(NO_SENSE);

    } else {

        sense = scsi_parse_sense_buf(in_buf, in_len);

    }

    return scsi_build_sense_buf(buf, len, sense, fixed);

}
