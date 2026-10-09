/* 
 * Benchmark Sample ID : devign_8308
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a9d52a75634ac9aa7d101bf7f63e10bf6655a865
 */

static void parse_drive(DeviceState *dev, const char *str, void **ptr,

                        const char *propname, Error **errp)

{

    BlockBackend *blk;



    blk = blk_by_name(str);

    if (!blk) {

        error_setg(errp, "Property '%s.%s' can't find value '%s'",

                   object_get_typename(OBJECT(dev)), propname, str);

        return;

    }

    if (blk_attach_dev(blk, dev) < 0) {

        DriveInfo *dinfo = blk_legacy_dinfo(blk);



        if (dinfo->type != IF_NONE) {

            error_setg(errp, "Drive '%s' is already in use because "

                       "it has been automatically connected to another "

                       "device (did you need 'if=none' in the drive options?)",

                       str);

        } else {

            error_setg(errp, "Drive '%s' is already in use by another device",

                       str);

        }

        return;

    }

    *ptr = blk;

}
