/* 
 * Benchmark Sample ID : devign_8224
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=55e1819c509b3d9c10a54678b9c585bbda13889e
 */

static void qnull_destroy_obj(QObject *obj)

{

    assert(0);

}
