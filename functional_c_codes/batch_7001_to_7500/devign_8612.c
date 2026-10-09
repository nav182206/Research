/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8612
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static void init_types(void)

{

    static int inited;

    int i;



    if (inited) {

        return;

    }



    for (i = 0; i < MODULE_INIT_MAX; i++) {

        TAILQ_INIT(&init_type_list[i]);

    }



    inited = 1;

}
