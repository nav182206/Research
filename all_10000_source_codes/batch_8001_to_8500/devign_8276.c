/* 
 * Benchmark Sample ID : devign_8276
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=abd696e4f74a9d30801c6ae2693efe4e5979c2f2
 */

static int zipl_magic(uint8_t *ptr)

{

    uint32_t *p = (void*)ptr;

    uint32_t *z = (void*)ZIPL_MAGIC;



    if (*p != *z) {

        debug_print_int("invalid magic", *p);

        virtio_panic("invalid magic");

    }



    return 1;

}
