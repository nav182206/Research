/* 
 * Benchmark Sample ID : devign_4133
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b098d56979d2f7fd707c5be85555d114353a28d
 */

Visitor *qmp_output_get_visitor(QmpOutputVisitor *v)

{

    return &v->visitor;

}
