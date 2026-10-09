/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4636
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f0278900d38b2d8d9531c484bd088d9a7d5d4ea2
 */

static void gen_spr_thrm (CPUPPCState *env)

{

    /* Thermal management */

    /* XXX : not implemented */

    spr_register(env, SPR_THRM1, "THRM1",

                 SPR_NOACCESS, SPR_NOACCESS,

                 &spr_read_generic, &spr_write_generic,

                 0x00000000);

    /* XXX : not implemented */

    spr_register(env, SPR_THRM2, "THRM2",

                 SPR_NOACCESS, SPR_NOACCESS,

                 &spr_read_generic, &spr_write_generic,

                 0x00000000);

    /* XXX : not implemented */

    spr_register(env, SPR_THRM3, "THRM3",

                 SPR_NOACCESS, SPR_NOACCESS,

                 &spr_read_generic, &spr_write_generic,

                 0x00000000);

}
