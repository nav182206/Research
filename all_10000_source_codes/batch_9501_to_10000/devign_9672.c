/* 
 * Benchmark Sample ID : devign_9672
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t cadence_ttc_read(void *opaque, target_phys_addr_t offset,

    unsigned size)

{

    uint32_t ret = cadence_ttc_read_imp(opaque, offset);



    DB_PRINT("addr: %08x data: %08x\n", offset, ret);

    return ret;

}
