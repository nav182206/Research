/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_176
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=41cbc23c5ca37a8b841915d7d252a02106d58b1e
 */

static char *regname(uint32_t addr)

{

    static char buf[16];

    if (addr < PCI_IO_SIZE) {

        const char *r = reg[addr / 4];

        if (r != 0) {

            sprintf(buf, "%s+%u", r, addr % 4);

        } else {

            sprintf(buf, "0x%02x", addr);

        }

    } else {

        sprintf(buf, "??? 0x%08x", addr);

    }

    return buf;

}
