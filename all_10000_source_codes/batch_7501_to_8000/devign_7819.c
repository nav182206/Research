/* 
 * Benchmark Sample ID : devign_7819
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static void qemu_opt_del(QemuOpt *opt)

{

    TAILQ_REMOVE(&opt->opts->head, opt, next);

    qemu_free((/* !const */ char*)opt->name);

    qemu_free((/* !const */ char*)opt->str);

    qemu_free(opt);

}
