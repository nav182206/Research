/* 
 * Benchmark Sample ID : devign_4695
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d9f62dde1303286b24ac8ce88be27e2b9b9c5f46
 */

static GenericList *qmp_output_next_list(Visitor *v, GenericList **listp,

                                         size_t size)

{

    GenericList *list = *listp;

    QmpOutputVisitor *qov = to_qov(v);

    QStackEntry *e = QTAILQ_FIRST(&qov->stack);



    assert(e);

    if (e->is_list_head) {

        e->is_list_head = false;

        return list;

    }



    return list ? list->next : NULL;

}
