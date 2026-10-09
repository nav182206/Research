/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_685
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c9262e8a84a29f22fbb5edde5d17f4f6166d5ae1
 */

static void virtio_set_status(struct subchannel_id schid,

                              unsigned long dev_addr)

{

    unsigned char status = dev_addr;

    if (run_ccw(schid, CCW_CMD_WRITE_STATUS, &status, sizeof(status))) {

        virtio_panic("Could not write status to host!\n");

    }

}
