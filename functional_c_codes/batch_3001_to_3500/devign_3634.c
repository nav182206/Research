/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3634
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=64607d088132abdb25bf30d93e97d0c8df7b364c
 */

static inline bool object_property_is_link(ObjectProperty *prop)

{

    return strstart(prop->type, "link<", NULL);

}
