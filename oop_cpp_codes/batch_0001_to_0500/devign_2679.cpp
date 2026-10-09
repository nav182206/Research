/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2679
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=55e1819c509b3d9c10a54678b9c585bbda13889e
 */

static void qlist_destroy_obj(QObject *obj)

{

    QList *qlist;

    QListEntry *entry, *next_entry;



    assert(obj != NULL);

    qlist = qobject_to_qlist(obj);



    QTAILQ_FOREACH_SAFE(entry, &qlist->head, next, next_entry) {

        QTAILQ_REMOVE(&qlist->head, entry, next);

        qobject_decref(entry->value);

        g_free(entry);

    }



    g_free(qlist);

}
