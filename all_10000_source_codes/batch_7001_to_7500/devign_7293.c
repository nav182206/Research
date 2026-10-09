/* 
 * Benchmark Sample ID : devign_7293
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=21a933ea33c820515f331c162c9f7053ca6f4129
 */

static void qemu_chr_parse_common(QemuOpts *opts, ChardevCommon *backend)

{

    const char *logfile = qemu_opt_get(opts, "logfile");



    backend->has_logfile = logfile != NULL;

    backend->logfile = logfile ? g_strdup(logfile) : NULL;



    backend->has_logappend = true;

    backend->logappend = qemu_opt_get_bool(opts, "logappend", false);

}
