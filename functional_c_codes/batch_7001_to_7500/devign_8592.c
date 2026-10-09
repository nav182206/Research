/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8592
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b2b012afdd9c03ba8a1619f45301d34f358d367b
 */

static void imx_eth_enable_rx(IMXFECState *s)

{

    IMXFECBufDesc bd;

    bool rx_ring_full;



    imx_fec_read_bd(&bd, s->rx_descriptor);



    rx_ring_full = !(bd.flags & ENET_BD_E);



    if (rx_ring_full) {

        FEC_PRINTF("RX buffer full\n");

    } else if (!s->regs[ENET_RDAR]) {

        qemu_flush_queued_packets(qemu_get_queue(s->nic));

    }



    s->regs[ENET_RDAR] = rx_ring_full ? 0 : ENET_RDAR_RDAR;

}
