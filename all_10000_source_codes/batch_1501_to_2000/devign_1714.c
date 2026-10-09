/* 
 * Benchmark Sample ID : devign_1714
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1e356fc14beaa3ece6c0e961bd479af58be3198b
 */

static void sigbus_handler(int signal)

{

    siglongjmp(sigjump, 1);

}
