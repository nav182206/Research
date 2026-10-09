/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6891
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=67fc07d3fba681f3362f7644a69b7a581a2670e8
 */

void muls64(int64_t *phigh, int64_t *plow, int64_t a, int64_t b)

{

#if defined(__x86_64__)

    __asm__ ("imul %0\n\t"

             : "=d" (*phigh), "=a" (*plow)

             : "a" (a), "0" (b)

             );

#else

    int64_t ph;

    uint64_t pm1, pm2, pl;



    pl = (uint64_t)((uint32_t)a) * (uint64_t)((uint32_t)b);

    pm1 = (a >> 32) * (uint32_t)b;

    pm2 = (uint32_t)a * (b >> 32);

    ph = (a >> 32) * (b >> 32);



    ph += (int64_t)pm1 >> 32;

    pm1 = (uint64_t)((uint32_t)pm1) + pm2 + (pl >> 32);



    *phigh = ph + ((int64_t)pm1 >> 32);

    *plow = (pm1 << 32) + (uint32_t)pl;

#endif

}
