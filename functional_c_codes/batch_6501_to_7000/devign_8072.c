/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8072
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=11b47038135442ec546dc348f2411e52e47549b8
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

        for (; i < count; i++)

            s->temp[0][2 * i    ] = s->temp[1][i] =

            s->temp[0][2 * i + 1] = s->temp[2][i] = 128;

    } else {

        for (i = 0; i < count; i++) {

            READ_2PIX(s->temp[0][2 * i    ], s->temp[1][i], 1);

            READ_2PIX(s->temp[0][2 * i + 1], s->temp[2][i], 2);

        }

    }

}
