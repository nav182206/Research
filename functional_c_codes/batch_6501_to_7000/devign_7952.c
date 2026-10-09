/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7952
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d2164ad35c411d97abd2aa5c6f160283d215e214
 */

static int get_uint16_equal(QEMUFile *f, void *pv, size_t size,

                            VMStateField *field)

{

    uint16_t *v = pv;

    uint16_t v2;

    qemu_get_be16s(f, &v2);



    if (*v == v2) {

        return 0;


    error_report("%x != %x", *v, v2);




    return -EINVAL;
