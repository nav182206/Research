/* 
 * Benchmark Sample ID : devign_1740
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9bb234b3b170299c39c9e88cfe7da5434a92d99d
 */

void OPPROTO op_sdiv_T1_T0(void)
{
    int64_t x0;
    int32_t x1;
    x0 = T0 | ((int64_t) (env->y) << 32);
    x1 = T1;
    x0 = x0 / x1;
    if ((int32_t) x0 != x0) {
	T0 = x0 < 0? 0x80000000: 0x7fffffff;
	T1 = 1;
    } else {
	T0 = x0;
	T1 = 0;
    FORCE_RET();
