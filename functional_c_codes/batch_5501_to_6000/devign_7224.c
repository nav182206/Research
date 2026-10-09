/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7224
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static void add_device_config(int type, const char *cmdline)

{

    struct device_config *conf;



    conf = qemu_mallocz(sizeof(*conf));

    conf->type = type;

    conf->cmdline = cmdline;

    TAILQ_INSERT_TAIL(&device_configs, conf, next);

}
