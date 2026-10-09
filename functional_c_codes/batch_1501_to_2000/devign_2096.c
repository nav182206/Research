/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2096
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2c62f08ddbf3fa80dc7202eb9a2ea60ae44e2cc5
 */

static void puv3_load_kernel(const char *kernel_filename)

{

    int size;



    assert(kernel_filename != NULL);



    /* only zImage format supported */

    size = load_image_targphys(kernel_filename, KERNEL_LOAD_ADDR,

            KERNEL_MAX_SIZE);

    if (size < 0) {

        hw_error("Load kernel error: '%s'\n", kernel_filename);

    }



    /* cheat curses that we have a graphic console, only under ocd console */

    graphic_console_init(NULL, NULL, NULL, NULL, NULL);

}
