/* 
 * Benchmark Sample ID : devign_4734
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=560f19f162529d691619ac69ed032321c7f5f1fb
 */

int64_t object_property_get_int(Object *obj, const char *name,

                                Error **errp)

{

    QObject *ret = object_property_get_qobject(obj, name, errp);

    QInt *qint;

    int64_t retval;



    if (!ret) {

        return -1;

    }

    qint = qobject_to_qint(ret);

    if (!qint) {

        error_setg(errp, QERR_INVALID_PARAMETER_TYPE, name, "int");

        retval = -1;

    } else {

        retval = qint_get_int(qint);

    }



    QDECREF(qint);

    return retval;

}
