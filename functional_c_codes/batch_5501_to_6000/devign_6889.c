/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6889
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=eff235eb2bcd7092901f4698a7907e742f3b7f2f
 */

static ExitStatus trans_fop_wed_0e(DisasContext *ctx, uint32_t insn,

                                   const DisasInsn *di)

{

    unsigned rt = assemble_rt64(insn);

    unsigned ra = extract32(insn, 21, 5);

    return do_fop_wed(ctx, rt, ra, di->f_wed);

}
