/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7958
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1546d487cf12da37d90a080813f8d57ac33036bf
 */

static int get_dimension(GetBitContext *gb, const int *dim)

{

    int t   = get_bits(gb, 3);

    int val = dim[t];

    if(val < 0)

        val = dim[get_bits1(gb) - val];

    if(!val){

        do{



            t = get_bits(gb, 8);

            val += t << 2;

        }while(t == 0xFF);

    }

    return val;

}
