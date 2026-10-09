/* 
 * Benchmark Sample ID : devign_4642
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c6c0e513600ba57c3e73b7151d3c0664438f7b5
 */

static void scsi_read_data(SCSIDevice *d, uint32_t tag)

{

    SCSIDiskState *s = DO_UPCAST(SCSIDiskState, qdev, d);

    SCSIDiskReq *r;



    r = scsi_find_request(s, tag);

    if (!r) {

        BADF("Bad read tag 0x%x\n", tag);

        /* ??? This is the wrong error.  */

        scsi_command_complete(r, CHECK_CONDITION, HARDWARE_ERROR);

        return;

    }



    scsi_read_request(r);

}
