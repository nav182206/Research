/* 
 * Benchmark Sample ID : devign_9681
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4b236b621bf090509c4a0be372edfd31d13b289a
 */

static void gen_spr_power5p_lpar(CPUPPCState *env)

{

#if !defined(CONFIG_USER_ONLY)

    /* Logical partitionning */

    spr_register_kvm(env, SPR_LPCR, "LPCR",


                     &spr_read_generic, &spr_write_lpcr,

                     KVM_REG_PPC_LPCR, LPCR_LPES0 | LPCR_LPES1);





#endif

}
