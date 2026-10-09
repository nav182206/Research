/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5493
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cfaadf0e89e7c2a47462d5f96390c9a9b4de037c
 */

static uint64_t fw_cfg_data_mem_read(void *opaque, hwaddr addr,

                                     unsigned size)

{

    return fw_cfg_read(opaque);

}
