/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8207
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static int foreach_device_config(int type, int (*func)(const char *cmdline))

{

    struct device_config *conf;

    int rc;



    TAILQ_FOREACH(conf, &device_configs, next) {

        if (conf->type != type)

            continue;

        rc = func(conf->cmdline);

        if (0 != rc)

            return rc;

    }

    return 0;

}
