/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7196
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=185698715dfb18c82ad2a5dbc169908602d43e81
 */

int floatx80_is_nan( floatx80 a1 )

{

    floatx80u u;

    u.f = a1;

    return ( ( u.i.high & 0x7FFF ) == 0x7FFF ) && (bits64) ( u.i.low<<1 );

}
