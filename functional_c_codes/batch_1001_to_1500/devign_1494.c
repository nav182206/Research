/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1494
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=dd3b73f3905c61c99f1d3fb58bc7ee380eb8aa2e
 */

int av_base64_decode(uint8_t *out, const char *in, int out_size)

{

    int i, v;

    uint8_t *dst = out;



    v = 0;

    for (i = 0; in[i] && in[i] != '='; i++) {

        unsigned int index= in[i]-43;

        if (index>=FF_ARRAY_ELEMS(map2) || map2[index] == 0xff)

            return -1;

        v = (v << 6) + map2[index];

        if (i & 3) {

            if (dst - out < out_size) {

                *dst++ = v >> (6 - 2 * (i & 3));

            }

        }

    }



    return dst - out;

}
