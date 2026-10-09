/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6758
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=af7e9e74c6a62a5bcd911726a9e88d28b61490e0
 */

static void openpic_src_write(void *opaque, hwaddr addr, uint64_t val,

                              unsigned len)

{

    OpenPICState *opp = opaque;

    int idx;



    DPRINTF("%s: addr %08x <= %08x\n", __func__, addr, val);

    if (addr & 0xF)

        return;

    addr = addr & 0xFFF0;

    idx = addr >> 5;

    if (addr & 0x10) {

        /* EXDE / IFEDE / IEEDE */

        write_IRQreg_ide(opp, idx, val);

    } else {

        /* EXVP / IFEVP / IEEVP */

        write_IRQreg_ipvp(opp, idx, val);

    }

}
