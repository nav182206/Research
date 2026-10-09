/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9499
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=eb513f82f04fab442cdef9db698dafc852275f7f
 */

void helper_stqf(CPUSPARCState *env, target_ulong addr, int mem_idx)

{

    /* XXX add 128 bit store */

    CPU_QuadU u;



    helper_check_align(env, addr, 7);

#if !defined(CONFIG_USER_ONLY)

    switch (mem_idx) {

    case MMU_USER_IDX:

        u.q = QT0;

        cpu_stq_user(env, addr, u.ll.upper);

        cpu_stq_user(env, addr + 8, u.ll.lower);

        break;

    case MMU_KERNEL_IDX:

        u.q = QT0;

        cpu_stq_kernel(env, addr, u.ll.upper);

        cpu_stq_kernel(env, addr + 8, u.ll.lower);

        break;

#ifdef TARGET_SPARC64

    case MMU_HYPV_IDX:

        u.q = QT0;

        cpu_stq_hypv(env, addr, u.ll.upper);

        cpu_stq_hypv(env, addr + 8, u.ll.lower);

        break;

#endif

    default:

        DPRINTF_MMU("helper_stqf: need to check MMU idx %d\n", mem_idx);

        break;

    }

#else

    u.q = QT0;

    stq_raw(address_mask(env, addr), u.ll.upper);

    stq_raw(address_mask(env, addr + 8), u.ll.lower);

#endif

}
