/* 
 * Benchmark Sample ID : devign_6455
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ad0ebb91cd8b5fdc4a583b03645677771f420a46
 */

void stb_tce(VIOsPAPRDevice *dev, uint64_t taddr, uint8_t val)

{

    spapr_tce_dma_write(dev, taddr, &val, sizeof(val));

}
