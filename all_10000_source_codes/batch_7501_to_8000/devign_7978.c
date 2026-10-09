/* 
 * Benchmark Sample ID : devign_7978
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=55e1819c509b3d9c10a54678b9c585bbda13889e
 */

QList *qlist_new(void)

{

    QList *qlist;



    qlist = g_malloc(sizeof(*qlist));

    QTAILQ_INIT(&qlist->head);

    QOBJECT_INIT(qlist, &qlist_type);



    return qlist;

}
