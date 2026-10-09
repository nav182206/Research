/* 
 * Benchmark Sample ID : devign_7779
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=488a1a5dfe9a9ba57fa6c6b6b98136ea494e0296
 */

static void pcnet_aprom_writeb(void *opaque, uint32_t addr, uint32_t val)

{

    PCNetState *s = opaque;

#ifdef PCNET_DEBUG

    printf("pcnet_aprom_writeb addr=0x%08x val=0x%02x\n", addr, val);

#endif

    /* Check APROMWE bit to enable write access */

    if (pcnet_bcr_readw(s,2) & 0x100)

        s->prom[addr & 15] = val;

}
