/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1634
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f2c55d1735175ab37ab9f69854460087112d2756
 */

int s390_virtio_hypercall(CPUS390XState *env)

{

    s390_virtio_fn fn = s390_diag500_table[env->regs[1]];



    if (!fn) {

        return -EINVAL;

    }



    return fn(&env->regs[2]);

}
