/* 
 * Benchmark Sample ID : devign_8814
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f090c9d4ad5812fb92843d6470a1111c15190c4c
 */

INLINE int16 extractFloat32Exp( float32 a )

{



    return ( a>>23 ) & 0xFF;



}
