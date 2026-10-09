/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6400
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f090c9d4ad5812fb92843d6470a1111c15190c4c
 */

int float64_le_quiet( float64 a, float64 b STATUS_PARAM )

{

    flag aSign, bSign;



    if (    ( ( extractFloat64Exp( a ) == 0x7FF ) && extractFloat64Frac( a ) )

         || ( ( extractFloat64Exp( b ) == 0x7FF ) && extractFloat64Frac( b ) )

       ) {

        if ( float64_is_signaling_nan( a ) || float64_is_signaling_nan( b ) ) {

            float_raise( float_flag_invalid STATUS_VAR);

        }

        return 0;

    }

    aSign = extractFloat64Sign( a );

    bSign = extractFloat64Sign( b );

    if ( aSign != bSign ) return aSign || ( (bits64) ( ( a | b )<<1 ) == 0 );

    return ( a == b ) || ( aSign ^ ( a < b ) );



}
