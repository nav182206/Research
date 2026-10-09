/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3586
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ad674e53b5cce265fadafbde2c6a4f190345cd00
 */

static void next(DBDMA_channel *ch)

{

    uint32_t cp;



    ch->regs[DBDMA_STATUS] &= cpu_to_be32(~BT);



    cp = be32_to_cpu(ch->regs[DBDMA_CMDPTR_LO]);

    ch->regs[DBDMA_CMDPTR_LO] = cpu_to_be32(cp + sizeof(dbdma_cmd));

    dbdma_cmdptr_load(ch);

}
