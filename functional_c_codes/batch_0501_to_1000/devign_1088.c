/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1088
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=45ed0be146b7433d1123f09eb1a984210a311625
 */

static void gen_spr_power8_fscr(CPUPPCState *env)

{

    spr_register_kvm(env, SPR_FSCR, "FSCR",

                     SPR_NOACCESS, SPR_NOACCESS,

                     &spr_read_generic, &spr_write_generic,

                     KVM_REG_PPC_FSCR, 0x00000000);

}
