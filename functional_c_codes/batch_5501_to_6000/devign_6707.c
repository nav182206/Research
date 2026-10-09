/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6707
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a15fcc3cf69ee3d408f60d6cc316488d2b0249b4
 */

void visit_type_enum(Visitor *v, const char *name, int *obj,

                     const char *const strings[], Error **errp)

{

    assert(obj && strings);

    if (v->type == VISITOR_INPUT) {

        input_type_enum(v, name, obj, strings, errp);

    } else if (v->type == VISITOR_OUTPUT) {

        output_type_enum(v, name, obj, strings, errp);

    }

}
