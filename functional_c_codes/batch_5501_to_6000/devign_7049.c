/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7049
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7e01376daea75e888c370aab521a7d4aeaf2ffd1
 */

void ioinst_handle_sal(S390CPU *cpu, uint64_t reg1)

{

    /* We do not provide address limit checking, so let's suppress it. */

    if (SAL_REG1_INVALID(reg1) || reg1 & 0x000000000000ffff) {

        program_interrupt(&cpu->env, PGM_OPERAND, 2);

    }

}
