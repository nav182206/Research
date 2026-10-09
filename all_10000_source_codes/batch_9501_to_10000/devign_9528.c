/* 
 * Benchmark Sample ID : devign_9528
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3db211f3c80bb996a704d665fe275619f728bd4
 */

static void qmp_output_start_list(Visitor *v, const char *name,

                                  GenericList **listp, size_t size,

                                  Error **errp)

{

    QmpOutputVisitor *qov = to_qov(v);

    QList *list = qlist_new();



    qmp_output_add(qov, name, list);

    qmp_output_push(qov, list, listp);

}
