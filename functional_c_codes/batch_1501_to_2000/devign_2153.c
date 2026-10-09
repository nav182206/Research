/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2153
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8089b7fa8c5b5a48cc7101daa4be891d0ead5a5e
 */

AVRational av_get_q(void *obj, const char *name, const AVOption **o_out)

{

    int64_t intnum=1;

    double num=1;

    int den=1;



    av_get_number(obj, name, o_out, &num, &den, &intnum);

    if (num == 1.0 && (int)intnum == intnum)

        return (AVRational){intnum, den};

    else

        return av_d2q(num*intnum/den, 1<<24);

}
