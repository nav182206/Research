/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1143
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=966439a67830239a6c520c5df6c55627b8153c8b
 */

void OPPROTO op_set_Rc0 (void)

{

    env->crf[0] = T0 | xer_ov;

    RETURN();

}
