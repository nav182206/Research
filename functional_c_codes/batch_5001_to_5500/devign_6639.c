/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6639
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2a74440547ea0a15195224fa2b7784b267cbfe15
 */

QError *qerror_from_info(const char *file, int linenr, const char *func,

                         const char *fmt, va_list *va)

{

    QError *qerr;



    qerr = qerror_new();

    loc_save(&qerr->loc);

    qerr->linenr = linenr;

    qerr->file = file;

    qerr->func = func;



    if (!fmt) {

        qerror_abort(qerr, "QDict not specified");

    }



    qerror_set_data(qerr, fmt, va);

    qerror_set_desc(qerr, fmt);



    return qerr;

}
