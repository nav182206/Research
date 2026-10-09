/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3954
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4b3fc37788fe5a9c6ec0c43863c78604db40cbb3
 */

static void gen_spr_970_lpar(CPUPPCState *env)

{

    /* Logical partitionning */

    /* PPC970: HID4 is effectively the LPCR */

    spr_register(env, SPR_970_HID4, "HID4",

                 SPR_NOACCESS, SPR_NOACCESS,

                 &spr_read_generic, &spr_write_generic,

                 0x00000000);

}
