/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7681
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ee785fed5dd035d4b12142cacec6d3c344426dec
 */

void set_numa_modes(void)

{

    CPUArchState *env;

    int i;



    for (env = first_cpu; env != NULL; env = env->next_cpu) {

        for (i = 0; i < nb_numa_nodes; i++) {

            if (node_cpumask[i] & (1 << env->cpu_index)) {

                env->numa_node = i;

            }

        }

    }

}
