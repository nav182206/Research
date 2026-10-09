/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3452
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=23802b4fe0cf5821b72aa5bc682e38c8c91bb168
 */

void qtest_init(const char *qtest_chrdev, const char *qtest_log)

{

    CharDriverState *chr;



    chr = qemu_chr_new("qtest", qtest_chrdev, NULL);



    qemu_chr_add_handlers(chr, qtest_can_read, qtest_read, qtest_event, chr);

    qemu_chr_fe_set_echo(chr, true);



    inbuf = g_string_new("");



    if (qtest_log) {

        if (strcmp(qtest_log, "none") != 0) {

            qtest_log_fp = fopen(qtest_log, "w+");

        }

    } else {

        qtest_log_fp = stderr;

    }



    qtest_chr = chr;

}
