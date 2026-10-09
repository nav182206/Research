/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8264
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

void bdrv_add_key(BlockDriverState *bs, const char *key, Error **errp)

{

    if (key) {

        if (!bdrv_is_encrypted(bs)) {

            error_setg(errp, "Node '%s' is not encrypted",

                      bdrv_get_device_or_node_name(bs));

        } else if (bdrv_set_key(bs, key) < 0) {

            error_set(errp, QERR_INVALID_PASSWORD);

        }

    } else {

        if (bdrv_key_required(bs)) {

            error_set(errp, ERROR_CLASS_DEVICE_ENCRYPTED,

                      "'%s' (%s) is encrypted",

                      bdrv_get_device_or_node_name(bs),

                      bdrv_get_encrypted_filename(bs));

        }

    }

}
