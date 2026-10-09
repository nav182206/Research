/* 
 * Benchmark Sample ID : devign_3942
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=72902672dc2ed6281cdb205259c1d52ecf01f6b2
 */

uint64_t HELPER(neon_add_saturate_u64)(uint64_t src1, uint64_t src2)

{

    uint64_t res;



    res = src1 + src2;

    if (res < src1) {

        env->QF = 1;

        res = ~(uint64_t)0;

    }

    return res;

}
