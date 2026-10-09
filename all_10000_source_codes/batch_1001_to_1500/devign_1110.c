/* 
 * Benchmark Sample ID : devign_1110
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=130257dc443574a9da91dc293665be2cfc40245a
 */

static void qemu_chr_parse_serial(QemuOpts *opts, ChardevBackend *backend,

                                  Error **errp)

{

    const char *device = qemu_opt_get(opts, "path");



    if (device == NULL) {

        error_setg(errp, "chardev: serial/tty: no device path given");

        return;

    }

    backend->serial = g_new0(ChardevHostdev, 1);

    backend->serial->device = g_strdup(device);

}
