/* 
 * Benchmark Sample ID : devign_2155
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=185698715dfb18c82ad2a5dbc169908602d43e81
 */

int float32_is_nan( float32 a1 )

{

    float32u u;

    uint64_t a;

    u.f = a1;

    a = u.i;

    return ( 0xFF800000 < ( a<<1 ) );

}
