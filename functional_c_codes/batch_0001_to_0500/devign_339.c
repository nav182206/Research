/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_339
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=599d0c45615b7d099d256738a586d0f63bc707e6
 */

static int xen_host_pci_config_open(XenHostPCIDevice *d)

{

    char path[PATH_MAX];

    int rc;



    rc = xen_host_pci_sysfs_path(d, "config", path, sizeof (path));

    if (rc) {

        return rc;

    }

    d->config_fd = open(path, O_RDWR);

    if (d->config_fd < 0) {

        return -errno;

    }

    return 0;

}
