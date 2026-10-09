/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1024
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e12c08d3b67c4f4e5a16ee815188fc13632530ce
 */

static void test_machine(const void *data)

{

    const testdef_t *test = data;

    char tmpname[] = "/tmp/qtest-boot-serial-XXXXXX";

    int fd;



    fd = mkstemp(tmpname);

    g_assert(fd != -1);



    /*

     * Make sure that this test uses tcg if available: It is used as a

     * fast-enough smoketest for that.

     */

    global_qtest = qtest_startf("-M %s,accel=tcg:kvm "

                                "-chardev file,id=serial0,path=%s "

                                "-no-shutdown -serial chardev:serial0 %s",

                                test->machine, tmpname, test->extra);

    unlink(tmpname);



    check_guest_output(test, fd);

    qtest_quit(global_qtest);



    close(fd);

}
