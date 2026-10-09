/* 
 * Benchmark Sample ID : devign_9842
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8be7e7e4c72c048b90e3482557954a24bba43ba7
 */

static int debugcon_parse(const char *devname)

{   

    QemuOpts *opts;



    if (!qemu_chr_new("debugcon", devname, NULL)) {

        exit(1);

    }

    opts = qemu_opts_create(qemu_find_opts("device"), "debugcon", 1);

    if (!opts) {

        fprintf(stderr, "qemu: already have a debugcon device\n");

        exit(1);

    }

    qemu_opt_set(opts, "driver", "isa-debugcon");

    qemu_opt_set(opts, "chardev", "debugcon");

    return 0;

}
