/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_3851
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2ccf97ec0f1b7a62a3220064f305454f3932c55a
 */

static inline void init_thread(struct target_pt_regs *_regs, struct image_info *infop)

{

    _regs->gpr[1] = infop->start_stack;

#if defined(TARGET_PPC64) && !defined(TARGET_ABI32)

    if (get_ppc64_abi(infop) < 2) {

        _regs->gpr[2] = ldq_raw(infop->entry + 8) + infop->load_bias;

        infop->entry = ldq_raw(infop->entry) + infop->load_bias;

    } else {

        _regs->gpr[12] = infop->entry;  /* r12 set to global entry address */

    }

#endif

    _regs->nip = infop->entry;

}
