/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2227
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=550830f9351291c585c963204ad9127998b1c1ce
 */

static inline void cow_set_bits(uint8_t *bitmap, int start, int64_t nb_sectors)

{

    int64_t bitnum = start, last = start + nb_sectors;

    while (bitnum < last) {

        if ((bitnum & 7) == 0 && bitnum + 8 <= last) {

            bitmap[bitnum / 8] = 0xFF;

            bitnum += 8;

            continue;

        }

        bitmap[bitnum/8] |= (1 << (bitnum % 8));

        bitnum++;

    }

}
