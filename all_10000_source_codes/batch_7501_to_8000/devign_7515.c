/* 
 * Benchmark Sample ID : devign_7515
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=98d23704138e0be17a3ed9eb2631077bf92cc028
 */

static int usbnet_can_receive(VLANClientState *nc)

{

    USBNetState *s = DO_UPCAST(NICState, nc, nc)->opaque;



    if (is_rndis(s) && !s->rndis_state == RNDIS_DATA_INITIALIZED) {

        return 1;

    }



    return !s->in_len;

}
