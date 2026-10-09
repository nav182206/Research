/* 
 * Benchmark Sample ID : devign_7088
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8be7e7e4c72c048b90e3482557954a24bba43ba7
 */

static void monitor_parse(const char *optarg, const char *mode)

{

    static int monitor_device_index = 0;

    QemuOpts *opts;

    const char *p;

    char label[32];

    int def = 0;



    if (strstart(optarg, "chardev:", &p)) {

        snprintf(label, sizeof(label), "%s", p);

    } else {

        snprintf(label, sizeof(label), "compat_monitor%d",

                 monitor_device_index);

        if (monitor_device_index == 0) {

            def = 1;

        }

        opts = qemu_chr_parse_compat(label, optarg);

        if (!opts) {

            fprintf(stderr, "parse error: %s\n", optarg);

            exit(1);

        }

    }



    opts = qemu_opts_create(qemu_find_opts("mon"), label, 1);

    if (!opts) {

        fprintf(stderr, "duplicate chardev: %s\n", label);

        exit(1);

    }

    qemu_opt_set(opts, "mode", mode);

    qemu_opt_set(opts, "chardev", label);

    if (def)

        qemu_opt_set(opts, "default", "on");

    monitor_device_index++;

}
