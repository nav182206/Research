/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1584
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=297a3646c2947ee64a6d42ca264039732c6218e0
 */

void visit_end_struct(Visitor *v, Error **errp)

{

    assert(!error_is_set(errp));

    v->end_struct(v, errp);

}
