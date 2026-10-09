/* 
 * Benchmark Sample ID : devign_4846
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f755dea79dc81b0d6a8f6414e0672e165e28d8ba
 */

void visit_type_size(Visitor *v, uint64_t *obj, const char *name, Error **errp)

{

    int64_t value;



    if (v->type_size) {

        v->type_size(v, obj, name, errp);

    } else if (v->type_uint64) {

        v->type_uint64(v, obj, name, errp);

    } else {

        value = *obj;

        v->type_int64(v, &value, name, errp);

        *obj = value;

    }

}
