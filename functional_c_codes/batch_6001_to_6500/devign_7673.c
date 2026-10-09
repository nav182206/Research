/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7673
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b2c98d9d392c87c9b9e975d30f79924719d9cbbe
 */

static void tcg_out_ld_abs(TCGContext *s, TCGType type, TCGReg dest, void *abs)

{

    intptr_t addr = (intptr_t)abs;



    if ((facilities & FACILITY_GEN_INST_EXT) && !(addr & 1)) {

        ptrdiff_t disp = tcg_pcrel_diff(s, abs) >> 1;

        if (disp == (int32_t)disp) {

            if (type == TCG_TYPE_I32) {

                tcg_out_insn(s, RIL, LRL, dest, disp);

            } else {

                tcg_out_insn(s, RIL, LGRL, dest, disp);

            }

            return;

        }

    }



    tcg_out_movi(s, TCG_TYPE_PTR, dest, addr & ~0xffff);

    tcg_out_ld(s, type, dest, dest, addr & 0xffff);

}
