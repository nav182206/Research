/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2831
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aa48dd9319dcee78ec17f4d516fb7bfc62b1a4d2
 */

static CPUArchState *find_cpu(uint32_t thread_id)

{

    CPUState *cpu;



    cpu = qemu_get_cpu(thread_id);

    if (cpu == NULL) {

        return NULL;

    }

    return cpu->env_ptr;

}
