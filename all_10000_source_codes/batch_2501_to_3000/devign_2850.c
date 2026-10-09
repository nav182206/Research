/* 
 * Benchmark Sample ID : devign_2850
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a0d1cbdacff5df4ded16b753b38fdd9da6092968
 */

static ssize_t eth_rx(NetClientState *nc, const uint8_t *buf, size_t size)

{

    struct xlx_ethlite *s = qemu_get_nic_opaque(nc);

    unsigned int rxbase = s->rxbuf * (0x800 / 4);



    /* DA filter.  */

    if (!(buf[0] & 0x80) && memcmp(&s->conf.macaddr.a[0], buf, 6))

        return size;



    if (s->regs[rxbase + R_RX_CTRL0] & CTRL_S) {

        D(qemu_log("ethlite lost packet %x\n", s->regs[R_RX_CTRL0]));





    D(qemu_log("%s %zd rxbase=%x\n", __func__, size, rxbase));





    memcpy(&s->regs[rxbase + R_RX_BUF0], buf, size);



    s->regs[rxbase + R_RX_CTRL0] |= CTRL_S;

    if (s->regs[R_RX_CTRL0] & CTRL_I) {

        eth_pulse_irq(s);




    /* If c_rx_pingpong was set flip buffers.  */

    s->rxbuf ^= s->c_rx_pingpong;

    return size;
