/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1900
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=563890c7c7e977842e2a35afe7a24d06d2103242
 */

QDict *qtest_qmpv(QTestState *s, const char *fmt, va_list ap)

{

    /* Send QMP request */

    socket_sendf(s->qmp_fd, fmt, ap);



    /* Receive reply */

    return qtest_qmp_receive(s);

}
