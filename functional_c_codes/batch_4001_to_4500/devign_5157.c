/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5157
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=56a6f02b8ce1fe41a2a9077593e46eca7d98267d
 */

static void qmp_output_end_struct(Visitor *v, Error **errp)

{

    QmpOutputVisitor *qov = to_qov(v);

    qmp_output_pop(qov);

}
