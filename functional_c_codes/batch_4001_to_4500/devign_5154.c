/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5154
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e57ca75ce3b2bd33102573a8c0555d62e1bcfceb
 */

static target_ulong h_read(PowerPCCPU *cpu, sPAPRMachineState *spapr,

                           target_ulong opcode, target_ulong *args)

{

    CPUPPCState *env = &cpu->env;

    target_ulong flags = args[0];

    target_ulong ptex = args[1];

    uint8_t *hpte;

    int i, ridx, n_entries = 1;



    if (!valid_ptex(cpu, ptex)) {

        return H_PARAMETER;

    }



    if (flags & H_READ_4) {

        /* Clear the two low order bits */

        ptex &= ~(3ULL);

        n_entries = 4;

    }



    hpte = env->external_htab + (ptex * HASH_PTE_SIZE_64);



    for (i = 0, ridx = 0; i < n_entries; i++) {

        args[ridx++] = ldq_p(hpte);

        args[ridx++] = ldq_p(hpte + (HASH_PTE_SIZE_64/2));

        hpte += HASH_PTE_SIZE_64;

    }



    return H_SUCCESS;

}
