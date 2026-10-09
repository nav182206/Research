/* 
 * Benchmark Sample ID : devign_3867
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=daa76aa416b1e18ab1fac650ff53d966d8f21f68
 */

static void test_parse_path_subprocess(void)

{

    /* All these should work without issue */

    qemu_set_log_filename("/tmp/qemu.log");

    qemu_set_log_filename("/tmp/qemu-%d.log");

    qemu_set_log_filename("/tmp/qemu.log.%d");

}
