/* 
 * Benchmark Sample ID : devign_2931
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8be7e7e4c72c048b90e3482557954a24bba43ba7
 */

static int balloon_parse(const char *arg)

{

    QemuOpts *opts;



    if (strcmp(arg, "none") == 0) {

        return 0;

    }



    if (!strncmp(arg, "virtio", 6)) {

        if (arg[6] == ',') {

            /* have params -> parse them */

            opts = qemu_opts_parse(qemu_find_opts("device"), arg+7, 0);

            if (!opts)

                return  -1;

        } else {

            /* create empty opts */

            opts = qemu_opts_create(qemu_find_opts("device"), NULL, 0);

        }

        qemu_opt_set(opts, "driver", "virtio-balloon");

        return 0;

    }



    return -1;

}
