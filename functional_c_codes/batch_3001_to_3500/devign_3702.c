/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3702
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ad674e53b5cce265fadafbde2c6a4f190345cd00
 */

static void kill_channel(DBDMA_channel *ch)

{

    DBDMA_DPRINTF("kill_channel\n");



    ch->regs[DBDMA_STATUS] |= cpu_to_be32(DEAD);

    ch->regs[DBDMA_STATUS] &= cpu_to_be32(~ACTIVE);



    qemu_irq_raise(ch->irq);

}
