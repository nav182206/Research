/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8218
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fa879d62eb51253d00b6920ce1d1d9d261370a49
 */

void bdrv_detach(BlockDriverState *bs, DeviceState *qdev)

{

    assert(bs->peer == qdev);

    bs->peer = NULL;

    bs->change_cb = NULL;

    bs->change_opaque = NULL;

}
