/* 
 * Benchmark Sample ID : devign_3996
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9307c4c1d93939db9b04117b654253af5113dc21
 */

static void do_loadvm(int argc, const char **argv)

{

    if (argc != 2) {

        help_cmd(argv[0]);

        return;

    }

    if (qemu_loadvm(argv[1]) < 0) 

        term_printf("I/O error when loading VM from '%s'\n", argv[1]);

}
