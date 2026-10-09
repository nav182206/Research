/* 
 * Benchmark Sample ID : devign_96
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=32bafa8fdd098d52fbf1102d5a5e48d29398c0aa
 */

static void qemu_chr_parse_stdio(QemuOpts *opts, ChardevBackend *backend,

                                 Error **errp)

{

    ChardevStdio *stdio;



    stdio = backend->u.stdio = g_new0(ChardevStdio, 1);

    qemu_chr_parse_common(opts, qapi_ChardevStdio_base(stdio));

    stdio->has_signal = true;

    stdio->signal = qemu_opt_get_bool(opts, "signal", true);

}
