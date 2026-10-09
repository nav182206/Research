/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5100
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=15c2f669e3fb2bc97f7b42d1871f595c0ac24af8
 */

static void qmp_input_end_struct(Visitor *v, Error **errp)

{

    QmpInputVisitor *qiv = to_qiv(v);



    qmp_input_pop(qiv, errp);

}
