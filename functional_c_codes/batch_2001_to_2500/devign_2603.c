/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2603
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c9a464420d7eb67dace1f630554245360b4c7c5b
 */

uint64_t helper_tick_get_count(void *opaque)

{

#if !defined(CONFIG_USER_ONLY)

    return cpu_tick_get_count(opaque);

#else

    return 0;

#endif

}
