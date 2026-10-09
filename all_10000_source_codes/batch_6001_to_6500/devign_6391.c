/* 
 * Benchmark Sample ID : devign_6391
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b2b012afdd9c03ba8a1619f45301d34f358d367b
 */

static int imx_eth_can_receive(NetClientState *nc)

{

    IMXFECState *s = IMX_FEC(qemu_get_nic_opaque(nc));



    FEC_PRINTF("\n");



    return s->regs[ENET_RDAR] ? 1 : 0;

}
