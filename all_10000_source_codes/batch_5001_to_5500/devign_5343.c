/* 
 * Benchmark Sample ID : devign_5343
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=599d0c45615b7d099d256738a586d0f63bc707e6
 */

static bool xen_host_pci_dev_is_virtfn(XenHostPCIDevice *d)

{

    char path[PATH_MAX];

    struct stat buf;



    if (xen_host_pci_sysfs_path(d, "physfn", path, sizeof (path))) {

        return false;

    }

    return !stat(path, &buf);

}
