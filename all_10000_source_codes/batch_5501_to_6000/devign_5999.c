/* 
 * Benchmark Sample ID : devign_5999
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f090c9d4ad5812fb92843d6470a1111c15190c4c
 */

int float64_lt( float64 a, float64 b STATUS_PARAM )

{

    flag aSign, bSign;



    if (    ( ( extractFloat64Exp( a ) == 0x7FF ) && extractFloat64Frac( a ) )

         || ( ( extractFloat64Exp( b ) == 0x7FF ) && extractFloat64Frac( b ) )

       ) {

        float_raise( float_flag_invalid STATUS_VAR);

        return 0;

    }

    aSign = extractFloat64Sign( a );

    bSign = extractFloat64Sign( b );

    if ( aSign != bSign ) return aSign && ( (bits64) ( ( a | b )<<1 ) != 0 );

    return ( a != b ) && ( aSign ^ ( a < b ) );



}
