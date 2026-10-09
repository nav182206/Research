/* 
 * Benchmark Sample ID : devign_3092
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f090c9d4ad5812fb92843d6470a1111c15190c4c
 */

float32 int64_to_float32( int64 a STATUS_PARAM )

{

    flag zSign;

    uint64 absA;

    int8 shiftCount;



    if ( a == 0 ) return 0;

    zSign = ( a < 0 );

    absA = zSign ? - a : a;

    shiftCount = countLeadingZeros64( absA ) - 40;

    if ( 0 <= shiftCount ) {

        return packFloat32( zSign, 0x95 - shiftCount, absA<<shiftCount );

    }

    else {

        shiftCount += 7;

        if ( shiftCount < 0 ) {

            shift64RightJamming( absA, - shiftCount, &absA );

        }

        else {

            absA <<= shiftCount;

        }

        return roundAndPackFloat32( zSign, 0x9C - shiftCount, absA STATUS_VAR );

    }



}
