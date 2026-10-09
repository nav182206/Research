/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5551
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7b62a955047934bab158e84ecb63cb432c193ace
 */

void ppc6xx_irq_init (CPUState *env)

{

    env->irq_inputs = (void **)qemu_allocate_irqs(&ppc6xx_set_irq, env, 6);

}
