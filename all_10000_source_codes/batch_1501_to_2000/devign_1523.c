/* 
 * Benchmark Sample ID : devign_1523
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=45bbbb466cf4a6280076ea5a51f67ef5bedee345
 */

int32_t idiv32(int32_t *q_ptr, int64_t num, int32_t den)

{

    *q_ptr = num / den;

    return num % den;

}
