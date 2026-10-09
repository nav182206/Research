/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6653
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3d344c2aabb7bc9b414321e3c52872901edebdda
 */

static void qmp_input_check_struct(Visitor *v, Error **errp)

{

    QmpInputVisitor *qiv = to_qiv(v);

    StackObject *tos = &qiv->stack[qiv->nb_stack - 1];



    assert(qiv->nb_stack > 0);



    if (qiv->strict) {

        GHashTable *const top_ht = tos->h;

        if (top_ht) {

            GHashTableIter iter;

            const char *key;



            g_hash_table_iter_init(&iter, top_ht);

            if (g_hash_table_iter_next(&iter, (void **)&key, NULL)) {

                error_setg(errp, QERR_QMP_EXTRA_MEMBER, key);

            }

        }

    }

}
