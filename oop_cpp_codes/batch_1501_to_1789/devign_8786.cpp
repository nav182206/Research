/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_8786
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a426e122173f36f05ea2cb72dcff77b7408546ce
 */

int kvm_insert_breakpoint(CPUState *current_env, target_ulong addr,

                          target_ulong len, int type)

{

    struct kvm_sw_breakpoint *bp;

    CPUState *env;

    int err;



    if (type == GDB_BREAKPOINT_SW) {

        bp = kvm_find_sw_breakpoint(current_env, addr);

        if (bp) {

            bp->use_count++;

            return 0;

        }



        bp = qemu_malloc(sizeof(struct kvm_sw_breakpoint));

        if (!bp)

            return -ENOMEM;



        bp->pc = addr;

        bp->use_count = 1;

        err = kvm_arch_insert_sw_breakpoint(current_env, bp);

        if (err) {

            free(bp);

            return err;

        }



        QTAILQ_INSERT_HEAD(&current_env->kvm_state->kvm_sw_breakpoints,

                          bp, entry);

    } else {

        err = kvm_arch_insert_hw_breakpoint(addr, len, type);

        if (err)

            return err;

    }



    for (env = first_cpu; env != NULL; env = env->next_cpu) {

        err = kvm_update_guest_debug(env, 0);

        if (err)

            return err;

    }

    return 0;

}
