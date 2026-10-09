/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_906
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f61eddcb2bb5cbbdd1d911b7e937db9affc29028
 */

static int debugcon_parse(const char *devname)

{

    QemuOpts *opts;



    if (!qemu_chr_new("debugcon", devname, NULL)) {

        exit(1);

    }

    opts = qemu_opts_create(qemu_find_opts("device"), "debugcon", 1, NULL);

    if (!opts) {

        fprintf(stderr, "qemu: already have a debugcon device\n");

        exit(1);

    }

    qemu_opt_set(opts, "driver", "isa-debugcon", &error_abort);

    qemu_opt_set(opts, "chardev", "debugcon", &error_abort);

    return 0;

}
