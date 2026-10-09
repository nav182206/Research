/* 
 * Benchmark Sample ID : devign_541
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4f4321c11ff6e98583846bfd6f0e81954924b003
 */

void usb_generic_async_ctrl_complete(USBDevice *s, USBPacket *p)

{

    if (p->len < 0) {

        s->setup_state = SETUP_STATE_IDLE;

    }



    switch (s->setup_state) {

    case SETUP_STATE_SETUP:

        if (p->len < s->setup_len) {

            s->setup_len = p->len;

        }

        s->setup_state = SETUP_STATE_DATA;

        p->len = 8;

        break;



    case SETUP_STATE_ACK:

        s->setup_state = SETUP_STATE_IDLE;

        p->len = 0;

        break;



    default:

        break;

    }

    usb_packet_complete(s, p);

}
