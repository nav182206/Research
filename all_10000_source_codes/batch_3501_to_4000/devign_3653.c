/* 
 * Benchmark Sample ID : devign_3653
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d9f62dde1303286b24ac8ce88be27e2b9b9c5f46
 */

static GenericList *next_list(Visitor *v, GenericList **list, size_t size)

{

    StringOutputVisitor *sov = to_sov(v);

    GenericList *ret = NULL;

    if (*list) {

        if (sov->head) {

            ret = *list;

        } else {

            ret = (*list)->next;

        }



        if (sov->head) {

            if (ret && ret->next == NULL) {

                sov->list_mode = LM_NONE;

            }

            sov->head = false;

        } else {

            if (ret && ret->next == NULL) {

                sov->list_mode = LM_END;

            }

        }

    }



    return ret;

}
