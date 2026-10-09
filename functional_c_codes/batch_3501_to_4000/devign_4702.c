/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4702
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a89f364ae8740dfc31b321eed9ee454e996dc3c1
 */

static void static_write(void *opaque, hwaddr offset, uint64_t value,

                         unsigned size)

{

#ifdef SPY

    printf("%s: value %08lx written at " PA_FMT "\n",

                    __FUNCTION__, value, offset);

#endif

}
