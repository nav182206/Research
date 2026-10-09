/* 
 * Benchmark Sample ID : devign_1042
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=eff235eb2bcd7092901f4698a7907e742f3b7f2f
 */

static ExitStatus trans_fop_dew_0c(DisasContext *ctx, uint32_t insn,

                                   const DisasInsn *di)

{

    unsigned rt = extract32(insn, 0, 5);

    unsigned ra = extract32(insn, 21, 5);

    return do_fop_dew(ctx, rt, ra, di->f_dew);

}
