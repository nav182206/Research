/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2471
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3a86a0fa76b5103a122b6e817b3827b2837f4956
 */

static GenericList *qmp_input_next_list(Visitor *v, GenericList **list,

                                        Error **errp)

{

    QmpInputVisitor *qiv = to_qiv(v);

    GenericList *entry;

    StackObject *so = &qiv->stack[qiv->nb_stack - 1];



    if (so->entry == NULL) {

        return NULL;

    }



    entry = g_malloc0(sizeof(*entry));

    if (*list) {

        so->entry = qlist_next(so->entry);

        if (so->entry == NULL) {

            g_free(entry);

            return NULL;

        }

        (*list)->next = entry;

    }



    return entry;

}
