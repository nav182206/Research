/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_331
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cde0fc7544ca590c83f349d4dcccf375d55d6042
 */

void qerror_report_internal(const char *file, int linenr, const char *func,

                            const char *fmt, ...)

{

    va_list va;

    QError *qerror;



    va_start(va, fmt);

    qerror = qerror_from_info(file, linenr, func, fmt, &va);

    va_end(va);



    if (cur_mon) {

        monitor_set_error(cur_mon, qerror);

    } else {

        qerror_print(qerror);

        QDECREF(qerror);

    }

}
