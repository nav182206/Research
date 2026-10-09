/* 
 * Benchmark Sample ID : devign_8461
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=56943e8cc14b7eeeab67d1942fa5d8bcafe3e53f
 */

void tcg_cpu_address_space_init(CPUState *cpu, AddressSpace *as)

{

    /* We only support one address space per cpu at the moment.  */

    assert(cpu->as == as);



    if (cpu->cpu_ases) {

        /* We've already registered the listener for our only AS */

        return;

    }



    cpu->cpu_ases = g_new0(CPUAddressSpace, 1);

    cpu->cpu_ases[0].cpu = cpu;

    cpu->cpu_ases[0].as = as;

    cpu->cpu_ases[0].tcg_as_listener.commit = tcg_commit;

    memory_listener_register(&cpu->cpu_ases[0].tcg_as_listener, as);

}
