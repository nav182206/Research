/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5531
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c89658008705d949c319df3fa6f400c481ad73e1
 */

int rtsp_next_attr_and_value(const char **p, char *attr, int attr_size, char *value, int value_size)

{

    skip_spaces(p);

    if(**p) {

        get_word_sep(attr, attr_size, "=", p);

        if (**p == '=')

            (*p)++;

        get_word_sep(value, value_size, ";", p);

        if (**p == ';')

            (*p)++;

        return 1;

    }

    return 0;

}
