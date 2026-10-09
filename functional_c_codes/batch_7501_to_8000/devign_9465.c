/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9465
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=245f7b51c0ea04fb2224b1127430a096c91aee70
 */

static void tight_palette_rgb2buf(uint32_t rgb, int bpp, uint8_t buf[6])

{

    memset(buf, 0, 6);



    if (bpp == 32) {

        buf[0] = ((rgb >> 24) & 0xFF);

        buf[1] = ((rgb >> 16) & 0xFF);

        buf[2] = ((rgb >>  8) & 0xFF);

        buf[3] = ((rgb >>  0) & 0xFF);

        buf[4] = ((buf[0] & 1) == 0) << 3 | ((buf[1] & 1) == 0) << 2;

        buf[4]|= ((buf[2] & 1) == 0) << 1 | ((buf[3] & 1) == 0) << 0;

        buf[0] |= 1;

        buf[1] |= 1;

        buf[2] |= 1;

        buf[3] |= 1;

    }

    if (bpp == 16) {

        buf[0] = ((rgb >> 8) & 0xFF);

        buf[1] = ((rgb >> 0) & 0xFF);

        buf[2] = ((buf[0] & 1) == 0) << 1 | ((buf[1] & 1) == 0) << 0;

        buf[0] |= 1;

        buf[1] |= 1;

    }

}
