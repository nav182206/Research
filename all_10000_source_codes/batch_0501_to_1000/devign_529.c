/* 
 * Benchmark Sample ID : devign_529
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9745807191a81c45970f780166f44a7f93b18653
 */

static void gen_ove_cy(DisasContext *dc, TCGv cy)

{

    if (dc->tb_flags & SR_OVE) {

        gen_helper_ove(cpu_env, cy);

    }

}
