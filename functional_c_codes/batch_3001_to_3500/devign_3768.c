/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3768
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=56a6f02b8ce1fe41a2a9077593e46eca7d98267d
 */

QObject *qmp_output_get_qobject(QmpOutputVisitor *qov)

{

    /* FIXME: we should require that a visit occurred, and that it is

     * complete (no starts without a matching end) */

    QObject *obj = qov->root;

    if (obj) {

        qobject_incref(obj);

    } else {

        obj = qnull();

    }

    return obj;

}
