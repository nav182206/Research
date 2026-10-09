/* 
 * Benchmark Sample ID : devign_6277
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ce140b176920b5b65184020735a3c65ed3e9aeda
 */

void qmp_input_visitor_cleanup(QmpInputVisitor *v)

{

    qobject_decref(v->stack[0].obj);

    g_free(v);

}
