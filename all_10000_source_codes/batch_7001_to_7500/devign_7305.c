/* 
 * Benchmark Sample ID : devign_7305
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ab31979a7e835832605f8425d0eaa5c74d1e6375
 */

static void encrypted_bdrv_it(void *opaque, BlockDriverState *bs)

{

    Error **errp = opaque;



    if (!error_is_set(errp) && bdrv_key_required(bs)) {

        error_set(errp, QERR_DEVICE_ENCRYPTED, bdrv_get_device_name(bs),

                  bdrv_get_encrypted_filename(bs));

    }

}
