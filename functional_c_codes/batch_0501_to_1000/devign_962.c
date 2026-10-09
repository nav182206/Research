/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_962
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b098d56979d2f7fd707c5be85555d114353a28d
 */

Visitor *string_output_get_visitor(StringOutputVisitor *sov)

{

    return &sov->visitor;

}
