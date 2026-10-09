/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2486
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0eb28a42284ec32e6f283985d2d638474a05eba4
 */

static void set_blocksize(Object *obj, Visitor *v, void *opaque,

                          const char *name, Error **errp)

{

    DeviceState *dev = DEVICE(obj);

    Property *prop = opaque;

    uint16_t value, *ptr = qdev_get_prop_ptr(dev, prop);

    Error *local_err = NULL;

    const int64_t min = 512;

    const int64_t max = 32768;



    if (dev->realized) {

        qdev_prop_set_after_realize(dev, name, errp);

        return;

    }



    visit_type_uint16(v, &value, name, &local_err);

    if (local_err) {

        error_propagate(errp, local_err);

        return;

    }

    if (value < min || value > max) {

        error_set(errp, QERR_PROPERTY_VALUE_OUT_OF_RANGE,

                  dev->id?:"", name, (int64_t)value, min, max);

        return;

    }



    /* We rely on power-of-2 blocksizes for bitmasks */

    if ((value & (value - 1)) != 0) {

        error_setg(errp,

                  "Property %s.%s doesn't take value '%" PRId64 "', it's not a power of 2",

                  dev->id ?: "", name, (int64_t)value);

        return;

    }



    *ptr = value;

}
