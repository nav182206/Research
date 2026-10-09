/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_249
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f090c9d4ad5812fb92843d6470a1111c15190c4c
 */

int64 float64_to_int64_round_to_zero( float64 a STATUS_PARAM )

{

    flag aSign;

    int16 aExp, shiftCount;

    bits64 aSig;

    int64 z;



    aSig = extractFloat64Frac( a );

    aExp = extractFloat64Exp( a );

    aSign = extractFloat64Sign( a );

    if ( aExp ) aSig |= LIT64( 0x0010000000000000 );

    shiftCount = aExp - 0x433;

    if ( 0 <= shiftCount ) {

        if ( 0x43E <= aExp ) {

            if ( a != LIT64( 0xC3E0000000000000 ) ) {

                float_raise( float_flag_invalid STATUS_VAR);

                if (    ! aSign

                     || (    ( aExp == 0x7FF )

                          && ( aSig != LIT64( 0x0010000000000000 ) ) )

                   ) {

                    return LIT64( 0x7FFFFFFFFFFFFFFF );

                }

            }

            return (sbits64) LIT64( 0x8000000000000000 );

        }

        z = aSig<<shiftCount;

    }

    else {

        if ( aExp < 0x3FE ) {

            if ( aExp | aSig ) STATUS(float_exception_flags) |= float_flag_inexact;

            return 0;

        }

        z = aSig>>( - shiftCount );

        if ( (bits64) ( aSig<<( shiftCount & 63 ) ) ) {

            STATUS(float_exception_flags) |= float_flag_inexact;

        }

    }

    if ( aSign ) z = - z;

    return z;



}
