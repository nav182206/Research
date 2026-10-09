/* 
 * Benchmark Sample ID : devign_8970
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9be385980d37e8f4fd33f605f5fb1c3d144170a8
 */

QObject *qlist_peek(QList *qlist)

{

    QListEntry *entry;

    QObject *ret;



    if (qlist == NULL || QTAILQ_EMPTY(&qlist->head)) {

        return NULL;

    }



    entry = QTAILQ_FIRST(&qlist->head);



    ret = entry->value;



    return ret;

}
