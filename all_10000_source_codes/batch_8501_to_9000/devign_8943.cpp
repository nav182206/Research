/* 
 * Benchmark Sample ID : devign_8943
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0dc083fe10c5cc848f36498b9157a336cbc8c7c1
 */

static void gen_spr_amr (CPUPPCState *env)

{

#ifndef CONFIG_USER_ONLY

    /* Virtual Page Class Key protection */

    /* The AMR is accessible either via SPR 13 or SPR 29.  13 is

     * userspace accessible, 29 is privileged.  So we only need to set

     * the kvm ONE_REG id on one of them, we use 29 */

    spr_register(env, SPR_UAMR, "UAMR",

                 &spr_read_uamr, &spr_write_uamr_pr,

                 &spr_read_uamr, &spr_write_uamr,

                 0);

    spr_register_kvm(env, SPR_AMR, "AMR",

                     SPR_NOACCESS, SPR_NOACCESS,

                     &spr_read_generic, &spr_write_generic,

                     KVM_REG_PPC_AMR, 0xffffffffffffffffULL);

    spr_register_kvm(env, SPR_UAMOR, "UAMOR",

                     SPR_NOACCESS, SPR_NOACCESS,

                     &spr_read_generic, &spr_write_generic,

                     KVM_REG_PPC_UAMOR, 0);

#endif /* !CONFIG_USER_ONLY */

}
