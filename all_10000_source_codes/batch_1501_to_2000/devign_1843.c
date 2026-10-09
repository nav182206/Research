/* 
 * Benchmark Sample ID : devign_1843
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=297a3646c2947ee64a6d42ca264039732c6218e0
 */

void visit_start_list(Visitor *v, const char *name, Error **errp)

{

    if (!error_is_set(errp)) {

        v->start_list(v, name, errp);

    }

}
