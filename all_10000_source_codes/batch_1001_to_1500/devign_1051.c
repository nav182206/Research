/* 
 * Benchmark Sample ID : devign_1051
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

void xen_config_cleanup(void)

{

    struct xs_dirs *d;



    TAILQ_FOREACH(d, &xs_cleanup, list) {

	xs_rm(xenstore, 0, d->xs_dir);

    }

}
