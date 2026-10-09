/* 
 * Benchmark Sample ID : devign_5363
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=97e89ee914411384dcda771d38bf89f13726d71e
 */

static void gen_check_privilege(DisasContext *dc)

{

    if (dc->cring) {

        gen_exception_cause(dc, PRIVILEGED_CAUSE);

        dc->is_jmp = DISAS_UPDATE;

    }

}
