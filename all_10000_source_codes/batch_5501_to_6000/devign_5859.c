/* 
 * Benchmark Sample ID : devign_5859
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=daa76aa416b1e18ab1fac650ff53d966d8f21f68
 */

static void test_parse_invalid_path(void)

{

    g_test_trap_subprocess ("/logging/parse_invalid_path/subprocess", 0, 0);

    g_test_trap_assert_passed();

    g_test_trap_assert_stdout("");

    g_test_trap_assert_stderr("Bad logfile format: /tmp/qemu-%d%d.log\n");

}
