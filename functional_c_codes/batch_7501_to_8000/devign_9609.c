/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9609
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=08b277ac46da8b02e50cec455eca7cb2d12ffcf0
 */

static int put_uint64_as_uint32(QEMUFile *f, void *pv, size_t size,

                                VMStateField *field, QJSON *vmdesc)

{

    uint64_t *v = pv;

    qemu_put_be32(f, *v);



    return 0;

}
