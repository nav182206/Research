/* 
 * Benchmark Sample ID : devign_1604
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=725e14e91f80b6b2c07b75b66b7b042a9fa9340c
 */

int read_targphys(const char *name,

                  int fd, target_phys_addr_t dst_addr, size_t nbytes)

{

    uint8_t *buf;

    size_t did;



    buf = g_malloc(nbytes);

    did = read(fd, buf, nbytes);

    if (did > 0)

        rom_add_blob_fixed("read", buf, did, dst_addr);

    g_free(buf);

    return did;

}
