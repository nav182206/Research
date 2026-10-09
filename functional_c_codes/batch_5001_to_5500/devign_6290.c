/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6290
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static inline void cris_alu_alloc_temps(DisasContext *dc, int size, TCGv *t)

{

	if (size == 4) {

		t[0] = cpu_R[dc->op2];

		t[1] = cpu_R[dc->op1];

	} else {

		t[0] = tcg_temp_new(TCG_TYPE_TL);

		t[1] = tcg_temp_new(TCG_TYPE_TL);

	}

}
