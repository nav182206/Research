/* 
 * Benchmark Sample ID : devign_8432
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=da6789c27c2ea71765cfab04bad9a42b5426f0bd
 */

static void nvdimm_init(Object *obj)

{

    object_property_add(obj, "label-size", "int",

                        nvdimm_get_label_size, nvdimm_set_label_size, NULL,

                        NULL, NULL);

}
