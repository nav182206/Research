/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9156
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=20a579de8484096d18e65751ebe63fee31551f04
 */

uint64_t hbitmap_serialization_granularity(const HBitmap *hb)

{

    /* Must hold true so that the shift below is defined

     * (ld(64) == 6, i.e. 1 << 6 == 64) */

    assert(hb->granularity < 64 - 6);



    /* Require at least 64 bit granularity to be safe on both 64 bit and 32 bit

     * hosts. */

    return UINT64_C(64) << hb->granularity;

}
