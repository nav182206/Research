/* 
 * Benchmark Sample ID : devign_4482
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2d3aa28cc2cf382aa04cd577e0be542175eea9bd
 */

void object_property_set_link(Object *obj, Object *value,

                              const char *name, Error **errp)

{

    object_property_set_str(obj, object_get_canonical_path(value),

                            name, errp);

}
