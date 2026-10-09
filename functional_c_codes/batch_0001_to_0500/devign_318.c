/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_318
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

struct XenDevice *xen_be_find_xendev(const char *type, int dom, int dev)

{

    struct XenDevice *xendev;



    TAILQ_FOREACH(xendev, &xendevs, next) {

	if (xendev->dom != dom)

	    continue;

	if (xendev->dev != dev)

	    continue;

	if (strcmp(xendev->type, type) != 0)

	    continue;

	return xendev;

    }

    return NULL;

}
