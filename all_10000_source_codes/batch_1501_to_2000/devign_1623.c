/* 
 * Benchmark Sample ID : devign_1623
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9307c4c1d93939db9b04117b654253af5113dc21
 */

static void do_change(int argc, const char **argv)

{

    BlockDriverState *bs;



    if (argc != 3) {

        help_cmd(argv[0]);

        return;

    }

    bs = bdrv_find(argv[1]);

    if (!bs) {

        term_printf("device not found\n");

        return;

    }

    if (eject_device(bs, 0) < 0)

        return;

    bdrv_open(bs, argv[2], 0);

}
