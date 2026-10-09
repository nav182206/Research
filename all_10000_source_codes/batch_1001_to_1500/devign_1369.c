/* 
 * Benchmark Sample ID : devign_1369
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7633378d5fbe932c9d38ae8961ef035d1ed26bfd
 */

static void aarch64_cpu_set_pc(CPUState *cs, vaddr value)

{

    ARMCPU *cpu = ARM_CPU(cs);

    /*

     * TODO: this will need updating for system emulation,

     * when the core may be in AArch32 mode.

     */

    cpu->env.pc = value;

}
