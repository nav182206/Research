/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_880
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b6fcf32d9b851a83dedcb609091236b97cc4a985
 */

static void visit_nested_struct(Visitor *v, void **native, Error **errp)

{

    visit_type_UserDefNested(v, (UserDefNested **)native, NULL, errp);

}
