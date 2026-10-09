/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6952
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b2c98d9d392c87c9b9e975d30f79924719d9cbbe
 */

static int tcg_match_add2i(TCGType type, tcg_target_long val)

{

    if (facilities & FACILITY_EXT_IMM) {

        if (type == TCG_TYPE_I32) {

            return 1;

        } else if (val >= -0xffffffffll && val <= 0xffffffffll) {

            return 1;

        }

    }

    return 0;

}
