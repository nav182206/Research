/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1022
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c0f4ce7751f0b9a9a7815f931a09a6c3de127cee
 */

static void do_change_block(const char *device, const char *filename, const char *fmt)

{

    BlockDriverState *bs;

    BlockDriver *drv = NULL;



    bs = bdrv_find(device);

    if (!bs) {

        term_printf("device not found\n");

        return;

    }

    if (fmt) {

        drv = bdrv_find_format(fmt);

        if (!drv) {

            term_printf("invalid format %s\n", fmt);

            return;

        }

    }

    if (eject_device(bs, 0) < 0)

        return;

    bdrv_open2(bs, filename, 0, drv);

    qemu_key_check(bs, filename);

}
