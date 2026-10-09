/* 
 * Benchmark Sample ID : devign_1141
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b14ef7c9ab41ea824c3ccadb070ad95567cca84e
 */

static void do_unassigned_access(target_ulong addr, int is_write, int is_exec,

                          int is_asi, int size)

#else

void do_unassigned_access(target_phys_addr_t addr, int is_write, int is_exec,

                          int is_asi, int size)

#endif

{

    CPUState *saved_env;



    /* XXX: hack to restore env in all cases, even if not called from

       generated code */

    saved_env = env;

    env = cpu_single_env;



#ifdef DEBUG_UNASSIGNED

    printf("Unassigned mem access to " TARGET_FMT_plx " from " TARGET_FMT_lx

           "\n", addr, env->pc);

#endif



    if (is_exec)

        raise_exception(TT_CODE_ACCESS);

    else

        raise_exception(TT_DATA_ACCESS);



    env = saved_env;

}
