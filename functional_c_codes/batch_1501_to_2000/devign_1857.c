/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1857
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static inline void t_gen_mov_preg_TN(DisasContext *dc, int r, TCGv tn)

{

	if (r < 0 || r > 15)

		fprintf(stderr, "wrong register write $p%d\n", r);

	if (r == PR_BZ || r == PR_WZ || r == PR_DZ)

		return;

	else if (r == PR_SRS)

		tcg_gen_andi_tl(cpu_PR[r], tn, 3);

	else {

		if (r == PR_PID) 

			tcg_gen_helper_0_1(helper_tlb_flush_pid, tn);

		if (dc->tb_flags & S_FLAG && r == PR_SPC) 

			tcg_gen_helper_0_1(helper_spc_write, tn);

		else if (r == PR_CCS)

			dc->cpustate_changed = 1;

		tcg_gen_mov_tl(cpu_PR[r], tn);

	}

}
