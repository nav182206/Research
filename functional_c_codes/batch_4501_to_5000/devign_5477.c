/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5477
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1984745ea8ad309a06690a83e91d031d21d709ff
 */

uint32_t nand_getio(DeviceState *dev)

{

    int offset;

    uint32_t x = 0;

    NANDFlashState *s = (NANDFlashState *) dev;



    /* Allow sequential reading */

    if (!s->iolen && s->cmd == NAND_CMD_READ0) {

        offset = (int) (s->addr & ((1 << s->addr_shift) - 1)) + s->offset;

        s->offset = 0;



        s->blk_load(s, s->addr, offset);

        if (s->gnd)

            s->iolen = (1 << s->page_shift) - offset;

        else

            s->iolen = (1 << s->page_shift) + (1 << s->oob_shift) - offset;

    }



    if (s->ce || s->iolen <= 0)

        return 0;



    for (offset = s->buswidth; offset--;) {

        x |= s->ioaddr[offset] << (offset << 3);

    }

    /* after receiving READ STATUS command all subsequent reads will

     * return the status register value until another command is issued

     */

    if (s->cmd != NAND_CMD_READSTATUS) {

        s->addr   += s->buswidth;

        s->ioaddr += s->buswidth;

        s->iolen  -= s->buswidth;

    }

    return x;

}
