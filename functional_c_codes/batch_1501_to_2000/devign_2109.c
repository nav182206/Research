/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2109
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b0068d75ebdb388c90b9d2c9833f17d12f323717
 */

static unsigned int rms(const int *data)

{

    int x;

    unsigned int res = 0x10000;

    int b = 0;



    for (x=0; x<10; x++) {

        res = (((0x1000000 - (*data) * (*data)) >> 12) * res) >> 12;



        if (res == 0)

            return 0;



        while (res <= 0x3fff) {

            b++;

            res <<= 2;

        }

        data++;

    }



    if (res > 0)

        res = t_sqrt(res);



    res >>= (b + 10);

    return res;

}
