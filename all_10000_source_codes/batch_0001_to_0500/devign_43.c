/* 
 * Benchmark Sample ID : devign_43
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=08b277ac46da8b02e50cec455eca7cb2d12ffcf0
 */

static int get_uint64_as_uint32(QEMUFile *f, void *pv, size_t size,

                                VMStateField *field)

{

    uint64_t *v = pv;

    *v = qemu_get_be32(f);

    return 0;

}
