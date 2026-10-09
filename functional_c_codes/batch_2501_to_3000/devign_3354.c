/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3354
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f090c9d4ad5812fb92843d6470a1111c15190c4c
 */

int float32_le_quiet( float32 a, float32 b STATUS_PARAM )

{

    flag aSign, bSign;



    if (    ( ( extractFloat32Exp( a ) == 0xFF ) && extractFloat32Frac( a ) )

         || ( ( extractFloat32Exp( b ) == 0xFF ) && extractFloat32Frac( b ) )

       ) {

        if ( float32_is_signaling_nan( a ) || float32_is_signaling_nan( b ) ) {

            float_raise( float_flag_invalid STATUS_VAR);

        }

        return 0;

    }

    aSign = extractFloat32Sign( a );

    bSign = extractFloat32Sign( b );

    if ( aSign != bSign ) return aSign || ( (bits32) ( ( a | b )<<1 ) == 0 );

    return ( a == b ) || ( aSign ^ ( a < b ) );



}
