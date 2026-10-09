/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7982
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7f74f0aa74a01698ef24459f7bc2a23f3880a2b8
 */

void ioinst_handle_stcrw(S390CPU *cpu, uint32_t ipb)

{

    CRW *crw;

    uint64_t addr;

    int cc;

    hwaddr len = sizeof(*crw);

    CPUS390XState *env = &cpu->env;



    addr = decode_basedisp_s(env, ipb);

    if (addr & 3) {

        program_interrupt(env, PGM_SPECIFICATION, 2);

        return;

    }

    crw = s390_cpu_physical_memory_map(env, addr, &len, 1);

    if (!crw || len != sizeof(*crw)) {

        program_interrupt(env, PGM_ADDRESSING, 2);

        goto out;

    }

    cc = css_do_stcrw(crw);

    /* 0 - crw stored, 1 - zeroes stored */

    setcc(cpu, cc);



out:

    s390_cpu_physical_memory_unmap(env, crw, len, 1);

}
