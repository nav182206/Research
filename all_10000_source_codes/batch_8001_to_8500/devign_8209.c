/* 
 * Benchmark Sample ID : devign_8209
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fa879d62eb51253d00b6920ce1d1d9d261370a49
 */

int qdev_prop_set_drive(DeviceState *dev, const char *name, BlockDriverState *value)

{

    int res;



    res = bdrv_attach(value, dev);

    if (res < 0) {

        error_report("Can't attach drive %s to %s.%s: %s",

                     bdrv_get_device_name(value),

                     dev->id ? dev->id : dev->info->name,

                     name, strerror(-res));

        return -1;

    }

    qdev_prop_set(dev, name, &value, PROP_TYPE_DRIVE);

    return 0;

}
