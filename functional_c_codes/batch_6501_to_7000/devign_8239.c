/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8239
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static unsigned int dec_move_sr(DisasContext *dc)

{

	DIS(fprintf (logfile, "move $s%u, $r%u\n", dc->op2, dc->op1));

	cris_cc_mask(dc, 0);

	tcg_gen_helper_0_2(helper_movl_reg_sreg, 

			   tcg_const_tl(dc->op1), tcg_const_tl(dc->op2));

	return 2;

}
