/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9883
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e3f5ec2b5e92706e3b807059f79b1fb5d936e567
 */

static void rtl8139_transfer_frame(RTL8139State *s, const uint8_t *buf, int size, int do_interrupt)

{

    if (!size)

    {

        DEBUG_PRINT(("RTL8139: +++ empty ethernet frame\n"));

        return;

    }



    if (TxLoopBack == (s->TxConfig & TxLoopBack))

    {

        DEBUG_PRINT(("RTL8139: +++ transmit loopback mode\n"));

        rtl8139_do_receive(s, buf, size, do_interrupt);

    }

    else

    {

        qemu_send_packet(s->vc, buf, size);

    }

}
