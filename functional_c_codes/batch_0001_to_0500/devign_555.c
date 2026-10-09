/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_555
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=297a3646c2947ee64a6d42ca264039732c6218e0
 */

void visit_type_str(Visitor *v, char **obj, const char *name, Error **errp)

{

    if (!error_is_set(errp)) {

        v->type_str(v, obj, name, errp);

    }

}
