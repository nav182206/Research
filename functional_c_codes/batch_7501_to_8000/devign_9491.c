/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9491
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=39ac8455106af1ed669b8e10223420cf1ac5b190
 */

target_ulong spapr_hypercall(CPUState *env, target_ulong opcode,

                             target_ulong *args)

{

    if (msr_pr) {

        hcall_dprintf("Hypercall made with MSR[PR]=1\n");

        return H_PRIVILEGE;

    }



    if ((opcode <= MAX_HCALL_OPCODE)

        && ((opcode & 0x3) == 0)) {

        spapr_hcall_fn fn = hypercall_table[opcode / 4];



        if (fn) {

            return fn(env, spapr, opcode, args);

        }

    }



    hcall_dprintf("Unimplemented hcall 0x" TARGET_FMT_lx "\n", opcode);

    return H_FUNCTION;

}
