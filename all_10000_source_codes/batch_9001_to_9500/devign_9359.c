/* 
 * Benchmark Sample ID : devign_9359
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=27bb0b2d6f80f058bdb6fcc8fcdfa69b0c8a6d71
 */

uint32_t hpet_in_legacy_mode(void)

{

    if (hpet_statep)

        return hpet_statep->config & HPET_CFG_LEGACY;

    else

        return 0;

}
