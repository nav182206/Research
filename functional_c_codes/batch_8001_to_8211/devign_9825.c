/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9825
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aca7aaf6287b6a9f688c1b115a76fdc056565a7e
 */

pixman_format_code_t qemu_default_pixman_format(int bpp, bool native_endian)

{

    if (native_endian) {

        switch (bpp) {

        case 15:

            return PIXMAN_x1r5g5b5;

        case 16:

            return PIXMAN_r5g6b5;

        case 24:

            return PIXMAN_r8g8b8;

        case 32:

            return PIXMAN_x8r8g8b8;

        }

    } else {

        switch (bpp) {

        case 24:

            return PIXMAN_b8g8r8;

        case 32:

            return PIXMAN_b8g8r8x8;

        break;

        }

    }

    g_assert_not_reached();

}
