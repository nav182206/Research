/* 
 * Benchmark Sample ID : devign_2127
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static unsigned int dec_btstq(DisasContext *dc)

{

	TCGv l0;

	dc->op1 = EXTRACT_FIELD(dc->ir, 0, 4);

	DIS(fprintf (logfile, "btstq %u, $r%d\n", dc->op1, dc->op2));



	cris_cc_mask(dc, CC_MASK_NZ);

	l0 = tcg_temp_local_new(TCG_TYPE_TL);

	cris_alu(dc, CC_OP_BTST,

		 l0, cpu_R[dc->op2], tcg_const_tl(dc->op1), 4);

	cris_update_cc_op(dc, CC_OP_FLAGS, 4);

	t_gen_mov_preg_TN(dc, PR_CCS, l0);

	dc->flags_uptodate = 1;

	tcg_temp_free(l0);

	return 2;

}
