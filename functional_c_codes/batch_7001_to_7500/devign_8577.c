/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8577
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=297a3646c2947ee64a6d42ca264039732c6218e0
 */

static void visit_type_TestStruct(Visitor *v, TestStruct **obj,

                                  const char *name, Error **errp)

{

    Error *err = NULL;



    visit_start_struct(v, (void **)obj, "TestStruct", name, sizeof(TestStruct),

                       &err);

    if (err) {

        goto out;

    }



    visit_type_int(v, &(*obj)->integer, "integer", &err);

    visit_type_bool(v, &(*obj)->boolean, "boolean", &err);

    visit_type_str(v, &(*obj)->string, "string", &err);



    visit_end_struct(v, &err);



out:

    error_propagate(errp, err);

}
