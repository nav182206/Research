/* 
 * Benchmark Sample ID : devign_4079
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ec53b45bcd1f74f7a4c31331fa6d50b402cd6d26
 */

int cpu_breakpoint_remove(CPUState *cpu, vaddr pc, int flags)

{

#if defined(TARGET_HAS_ICE)

    CPUBreakpoint *bp;



    QTAILQ_FOREACH(bp, &cpu->breakpoints, entry) {

        if (bp->pc == pc && bp->flags == flags) {

            cpu_breakpoint_remove_by_ref(cpu, bp);

            return 0;

        }

    }

    return -ENOENT;

#else

    return -ENOSYS;

#endif

}
