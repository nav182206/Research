/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4279
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3db211f3c80bb996a704d665fe275619f728bd4
 */

static void qmp_output_start_struct(Visitor *v, const char *name, void **obj,

                                    size_t unused, Error **errp)

{

    QmpOutputVisitor *qov = to_qov(v);

    QDict *dict = qdict_new();



    qmp_output_add(qov, name, dict);

    qmp_output_push(qov, dict, obj);

}
