/* 
 * Benchmark Sample ID : devign_838
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a340046614644a8958883954b96e92a87a5e78f7
 */

static void set_pci_devfn(Object *obj, Visitor *v, void *opaque,

                          const char *name, Error **errp)

{

    DeviceState *dev = DEVICE(obj);

    Property *prop = opaque;

    uint32_t *ptr = qdev_get_prop_ptr(dev, prop);

    unsigned int slot, fn, n;

    Error *local_err = NULL;

    char *str = (char *)"";



    if (dev->state != DEV_STATE_CREATED) {

        error_set(errp, QERR_PERMISSION_DENIED);

        return;

    }



    visit_type_str(v, &str, name, &local_err);

    if (local_err) {

        error_free(local_err);

        return set_int32(obj, v, opaque, name, errp);

    }



    if (sscanf(str, "%x.%x%n", &slot, &fn, &n) != 2) {

        fn = 0;

        if (sscanf(str, "%x%n", &slot, &n) != 1) {

            goto invalid;

        }

    }

    if (str[n] != '\0' || fn > 7 || slot > 31) {

        goto invalid;

    }

    *ptr = slot << 3 | fn;

    return;



invalid:

    error_set_from_qdev_prop_error(errp, EINVAL, dev, prop, str);

}
