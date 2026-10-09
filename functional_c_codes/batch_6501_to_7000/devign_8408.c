/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8408
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ff71f2e8cacefae99179993204172bc65e4303df
 */

static int rtl8139_can_receive(VLANClientState *nc)

{

    RTL8139State *s = DO_UPCAST(NICState, nc, nc)->opaque;

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
