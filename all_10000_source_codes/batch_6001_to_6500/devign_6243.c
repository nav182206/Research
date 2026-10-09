/* 
 * Benchmark Sample ID : devign_6243
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=808fb9f277abda16601e9db938d29aeaf2548585
 */

static int eth_can_rx(NetClientState *nc)

{

    struct xlx_ethlite *s = DO_UPCAST(NICState, nc, nc)->opaque;

    int r;

    r = !(s->regs[R_RX_CTRL0] & CTRL_S);

    return r;

}
