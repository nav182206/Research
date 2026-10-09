/* 
 * Benchmark Sample ID : devign_4031
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=afea4e1410654154018587dd35c1b250ba4d8ec4
 */

static bool megasas_use_msi(MegasasState *s)

{

    return s->msi != ON_OFF_AUTO_OFF;

}
