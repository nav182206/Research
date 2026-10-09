/* 
 * Benchmark Sample ID : devign_2757
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c3203fa5b2c17a1c446e44c87788fef21b4af5f4
 */

static int get_current_cpu(void)

{

  return cpu_single_env->cpu_index;

}
