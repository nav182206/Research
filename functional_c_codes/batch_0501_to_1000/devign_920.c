/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_920
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6c8d56a2e95712a6206a2671d2b04b2e59cabc0b
 */

static uint64_t fw_cfg_comb_read(void *opaque, hwaddr addr,

                                 unsigned size)

{

    return fw_cfg_read(opaque);

}
