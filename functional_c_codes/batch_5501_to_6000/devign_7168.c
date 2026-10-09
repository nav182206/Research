/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7168
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=42b6805cc1989f759f19e9d253527311741cbd3a
 */

static void decode_422_bitstream(HYuvContext *s, int count)

{

    int i;



    count /= 2;



    if (count >= (get_bits_left(&s->gb)) / (31 * 4)) {

        for (i = 0; i < count && get_bits_left(&s->gb) > 0; i++) {

            READ_2PIX(s->temp[0][2 * i    ], s->temp[1][i], 1);

            READ_2PIX(s->temp[0][2 * i + 1], s->temp[2][i], 2);

        }




    } else {

        for (i = 0; i < count; i++) {

            READ_2PIX(s->temp[0][2 * i    ], s->temp[1][i], 1);

            READ_2PIX(s->temp[0][2 * i + 1], s->temp[2][i], 2);

        }

    }

}
