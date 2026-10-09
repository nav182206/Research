/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5950
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2a74440547ea0a15195224fa2b7784b267cbfe15
 */

QError *qobject_to_qerror(const QObject *obj)

{

    if (qobject_type(obj) != QTYPE_QERROR) {

        return NULL;

    }



    return container_of(obj, QError, base);

}
