/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4559
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e3f5ec2b5e92706e3b807059f79b1fb5d936e567
 */

static int rtl8139_can_receive(void *opaque)

{

    RTL8139State *s = opaque;

    int avail;



    /* Receive (drop) packets if card is disabled.  */

    if (!s->clock_enabled)

      return 1;

    if (!rtl8139_receiver_enabled(s))

      return 1;



    if (rtl8139_cp_receiver_enabled(s)) {

        /* ??? Flow control not implemented in c+ mode.

           This is a hack to work around slirp deficiencies anyway.  */

        return 1;

    } else {

        avail = MOD2(s->RxBufferSize + s->RxBufPtr - s->RxBufAddr,

                     s->RxBufferSize);

        return (avail == 0 || avail >= 1514);

    }

}
