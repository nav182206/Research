/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_99
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d2889a3efc3851e62de69cb9d88fb784c28e0ed8
 */

void OPPROTO op_movl_npc_T0(void)

{

    env->npc = T0;

}
