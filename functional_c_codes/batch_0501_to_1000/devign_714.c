/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_714
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3db211f3c80bb996a704d665fe275619f728bd4
 */

static void qmp_output_type_str(Visitor *v, const char *name, char **obj,

                                Error **errp)

{

    QmpOutputVisitor *qov = to_qov(v);

    if (*obj) {

        qmp_output_add(qov, name, qstring_from_str(*obj));

    } else {

        qmp_output_add(qov, name, qstring_from_str(""));

    }

}
