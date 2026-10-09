/* 
 * Benchmark Sample ID : devign_1204
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2a74440547ea0a15195224fa2b7784b267cbfe15
 */

void qerror_print(QError *qerror)

{

    QString *qstring = qerror_human(qerror);

    loc_push_restore(&qerror->loc);

    error_report("%s", qstring_get_str(qstring));

    loc_pop(&qerror->loc);

    QDECREF(qstring);

}
