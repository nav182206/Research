/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5660
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a980f7f2c2f4d7e9a1eba4f804cd66dbd458b6d4
 */

static uint64_t qvirtio_scsi_alloc(QVirtIOSCSI *vs, size_t alloc_size,

                                   const void *data)

{

    uint64_t addr;



    addr = guest_alloc(vs->alloc, alloc_size);

    if (data) {

        memwrite(addr, data, alloc_size);

    }



    return addr;

}
