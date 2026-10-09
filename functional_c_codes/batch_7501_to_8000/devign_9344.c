/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9344
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3098dba01c7daab60762b6f6624ea88c0d6cb65a
 */

static int cpu_common_load(QEMUFile *f, void *opaque, int version_id)

{

    CPUState *env = opaque;



    if (version_id != CPU_COMMON_SAVE_VERSION)

        return -EINVAL;



    qemu_get_be32s(f, &env->halted);

    qemu_get_be32s(f, &env->interrupt_request);

    env->interrupt_request &= ~CPU_INTERRUPT_EXIT;

    tlb_flush(env, 1);



    return 0;

}
