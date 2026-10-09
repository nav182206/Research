/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1870
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a2b257d6212ade772473f86bf0637480b2578a7e
 */

static void *legacy_s390_alloc(size_t size)

{

    void *mem;



    mem = mmap((void *) 0x800000000ULL, size,

               PROT_EXEC|PROT_READ|PROT_WRITE,

               MAP_SHARED | MAP_ANONYMOUS | MAP_FIXED, -1, 0);

    return mem == MAP_FAILED ? NULL : mem;

}
