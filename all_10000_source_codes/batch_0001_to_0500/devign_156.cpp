/* 
 * Benchmark Sample ID : devign_156
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6e19a1379d3d12c2d8f934aa8154037a609f4507
 */

void tlb_fill(CPUState *env1, target_ulong addr, int is_write, int mmu_idx,

              void *retaddr)

{

    TranslationBlock *tb;

    CPUState *saved_env;

    unsigned long pc;

    int ret;



    saved_env = env;


    ret = cpu_arm_handle_mmu_fault(env, addr, is_write, mmu_idx);

    if (unlikely(ret)) {

        if (retaddr) {

            /* now we have a real cpu fault */

            pc = (unsigned long)retaddr;

            tb = tb_find_pc(pc);

            if (tb) {

                /* the PC is inside the translated code. It means that we have

                   a virtual CPU fault */

                cpu_restore_state(tb, env, pc);

            }

        }

        raise_exception(env->exception_index);

    }

    env = saved_env;

}
