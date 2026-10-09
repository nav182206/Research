/* 
 * Benchmark Sample ID : devign_9752
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a9fc37f6bc3f2ab90585cb16493da9f6dcfbfbcf
 */

static QObject *qobject_input_get_object(QObjectInputVisitor *qiv,

                                         const char *name,

                                         bool consume, Error **errp)

{

    StackObject *tos;

    QObject *qobj;

    QObject *ret;



    if (QSLIST_EMPTY(&qiv->stack)) {

        /* Starting at root, name is ignored. */

        assert(qiv->root);

        return qiv->root;

    }



    /* We are in a container; find the next element. */

    tos = QSLIST_FIRST(&qiv->stack);

    qobj = tos->obj;

    assert(qobj);



    if (qobject_type(qobj) == QTYPE_QDICT) {

        assert(name);

        ret = qdict_get(qobject_to_qdict(qobj), name);

        if (tos->h && consume && ret) {

            bool removed = g_hash_table_remove(tos->h, name);

            assert(removed);

        }

        if (!ret) {

            error_setg(errp, QERR_MISSING_PARAMETER, name);

        }

    } else {

        assert(qobject_type(qobj) == QTYPE_QLIST);

        assert(!name);

        ret = qlist_entry_obj(tos->entry);

        assert(ret);

        if (consume) {

            tos->entry = qlist_next(tos->entry);

        }

    }



    return ret;

}
