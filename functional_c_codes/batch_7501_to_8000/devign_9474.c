/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9474
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e58d695e6c3a5cfa0aa2fc91b87ade017ef28b05
 */

void visit_type_any(Visitor *v, const char *name, QObject **obj, Error **errp)

{

    v->type_any(v, name, obj, errp);

}
