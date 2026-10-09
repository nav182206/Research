/* 
 * Benchmark Sample ID : devign_5718
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d9f62dde1303286b24ac8ce88be27e2b9b9c5f46
 */

static void qmp_output_start_list(Visitor *v, const char *name, Error **errp)

{

    QmpOutputVisitor *qov = to_qov(v);

    QList *list = qlist_new();



    qmp_output_add(qov, name, list);

    qmp_output_push(qov, list);

}
