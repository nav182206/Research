/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8043
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b00c72180c36510bf9b124e190bd520e3b7e1358
 */

target_ulong helper_rdhwr_cpunum(CPUMIPSState *env)

{

    if ((env->hflags & MIPS_HFLAG_CP0) ||

        (env->CP0_HWREna & (1 << 0)))

        return env->CP0_EBase & 0x3ff;

    else

        do_raise_exception(env, EXCP_RI, GETPC());



    return 0;

}
