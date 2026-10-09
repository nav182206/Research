/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2973
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5039d6e23586fe6bbedc5e4fe302b48a66890ade
 */

static void cpu_request_exit(void *opaque, int irq, int level)

{

    CPUState *cpu = current_cpu;



    if (cpu && level) {

        cpu_exit(cpu);

    }

}
