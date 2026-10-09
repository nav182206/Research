/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4383
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=297a3646c2947ee64a6d42ca264039732c6218e0
 */

void visit_type_uint64(Visitor *v, uint64_t *obj, const char *name, Error **errp)

{

    int64_t value;

    if (!error_is_set(errp)) {

        if (v->type_uint64) {

            v->type_uint64(v, obj, name, errp);

        } else {

            value = *obj;

            v->type_int(v, &value, name, errp);

            *obj = value;

        }

    }

}
