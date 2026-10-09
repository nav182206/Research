/* 
 * Benchmark Sample ID : devign_3485
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ca5c1457d614fec718aaec7bdf3663dec37e1e50
 */

static void s390x_cpu_get_id(Object *obj, Visitor *v, const char *name,

                             void *opaque, Error **errp)

{

    S390CPU *cpu = S390_CPU(obj);

    int64_t value = cpu->id;



    visit_type_int(v, name, &value, errp);

}
