/* 
 * Benchmark Sample ID : devign_4007
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=643f59322432d77165329dfabe2d040d7e30dae8
 */

static void xenfb_copy_mfns(int mode, int count, unsigned long *dst, void *src)

{

    uint32_t *src32 = src;

    uint64_t *src64 = src;

    int i;



    for (i = 0; i < count; i++)

	dst[i] = (mode == 32) ? src32[i] : src64[i];

}
