/* 
 * Benchmark Sample ID : devign_909
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=880a7578381d1c7ed4d41c7599ae3cc06567a824
 */

static int gdb_breakpoint_insert(CPUState *env, target_ulong addr,

                                 target_ulong len, int type)

{

    switch (type) {

    case GDB_BREAKPOINT_SW:

    case GDB_BREAKPOINT_HW:

        return cpu_breakpoint_insert(env, addr, BP_GDB, NULL);

#ifndef CONFIG_USER_ONLY

    case GDB_WATCHPOINT_WRITE:

    case GDB_WATCHPOINT_READ:

    case GDB_WATCHPOINT_ACCESS:

        return cpu_watchpoint_insert(env, addr, len, xlat_gdb_type[type],

                                     NULL);

#endif

    default:

        return -ENOSYS;

    }

}
