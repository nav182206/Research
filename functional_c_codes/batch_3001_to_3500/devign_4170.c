/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4170
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=297a3646c2947ee64a6d42ca264039732c6218e0
 */

void visit_optional(Visitor *v, bool *present, const char *name,

                    Error **errp)

{

    if (!error_is_set(errp) && v->optional) {

        v->optional(v, present, name, errp);

    }

}
