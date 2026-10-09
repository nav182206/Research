/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9817
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=599d0c45615b7d099d256738a586d0f63bc707e6
 */

static int xen_host_pci_get_value(XenHostPCIDevice *d, const char *name,

                                  unsigned int *pvalue, int base)

{

    char path[PATH_MAX];

    char buf[XEN_HOST_PCI_GET_VALUE_BUFFER_SIZE];

    int fd, rc;

    unsigned long value;

    char *endptr;



    rc = xen_host_pci_sysfs_path(d, name, path, sizeof (path));

    if (rc) {

        return rc;

    }

    fd = open(path, O_RDONLY);

    if (fd == -1) {

        XEN_HOST_PCI_LOG("Error: Can't open %s: %s\n", path, strerror(errno));

        return -errno;

    }

    do {

        rc = read(fd, &buf, sizeof (buf) - 1);

        if (rc < 0 && errno != EINTR) {

            rc = -errno;

            goto out;

        }

    } while (rc < 0);

    buf[rc] = 0;

    value = strtol(buf, &endptr, base);

    if (endptr == buf || *endptr != '\n') {

        rc = -1;

    } else if ((value == LONG_MIN || value == LONG_MAX) && errno == ERANGE) {

        rc = -errno;

    } else {

        rc = 0;

        *pvalue = value;

    }

out:

    close(fd);

    return rc;

}
