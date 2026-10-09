/* 
 * Benchmark Sample ID : devign_6654
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eac5c7b8377f3f0e8262ab44e5ccb2c7ed060cdd
 */

int ff_get_line(AVIOContext *s, char *buf, int maxlen)

{

    int i = 0;

    char c;



    do {

        c = avio_r8(s);

        if (c && i < maxlen-1)

            buf[i++] = c;

    } while (c != '\n' && c != '\r' && c);

    if (c == '\r' && avio_r8(s) != '\n')

        avio_skip(s, -1);



    buf[i] = 0;

    return i;

}
