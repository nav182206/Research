/* 
 * Benchmark Sample ID : devign_3062
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d9f62dde1303286b24ac8ce88be27e2b9b9c5f46
 */

static void qapi_dealloc_end_list(Visitor *v)

{

    QapiDeallocVisitor *qov = to_qov(v);

    void *obj = qapi_dealloc_pop(qov);

    assert(obj == NULL); /* should've been list head tracker with no payload */

}
