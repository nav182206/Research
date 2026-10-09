/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3123
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static void put_bitmap(QEMUFile *f, void *pv, size_t size)

{

    unsigned long *bmp = pv;

    int i, idx = 0;

    for (i = 0; i < BITS_TO_U64S(size); i++) {

        uint64_t w = bmp[idx++];

        if (sizeof(unsigned long) == 4 && idx < BITS_TO_LONGS(size)) {

            w |= ((uint64_t)bmp[idx++]) << 32;

        }

        qemu_put_be64(f, w);

    }

}
