/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2800
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=57d3e1b3f52d07d215ed96df946ee01f8d9f9526
 */

void rng_backend_open(RngBackend *s, Error **errp)

{

    object_property_set_bool(OBJECT(s), true, "opened", errp);

}
