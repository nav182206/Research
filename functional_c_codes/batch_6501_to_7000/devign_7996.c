/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7996
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9307c4c1d93939db9b04117b654253af5113dc21
 */

static void do_eject(int argc, const char **argv)

{

    BlockDriverState *bs;

    const char **parg;

    int force;



    parg = argv + 1;

    if (!*parg) {

    fail:

        help_cmd(argv[0]);

        return;

    }

    force = 0;

    if (!strcmp(*parg, "-f")) {

        force = 1;

        parg++;

    }

    if (!*parg)

        goto fail;

    bs = bdrv_find(*parg);

    if (!bs) {

        term_printf("device not found\n");

        return;

    }

    eject_device(bs, force);

}
