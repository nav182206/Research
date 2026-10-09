/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9109
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4819446eae451a6e58d6ae41faefb5529af4e783
 */

static int webvtt_event_to_ass(AVBPrint *buf, const char *p)

{

    int i, again, skip = 0;



    while (*p) {



        for (i = 0; i < FF_ARRAY_ELEMS(webvtt_tag_replace); i++) {

            const char *from = webvtt_tag_replace[i].from;

            const size_t len = strlen(from);

            if (!strncmp(p, from, len)) {

                av_bprintf(buf, "%s", webvtt_tag_replace[i].to);

                p += len;

                again = 1;

                break;

            }

        }

        if (!*p)

            break;



        if (again) {

            again = 0;

            skip = 0;

            continue;

        }

        if (*p == '<')

            skip = 1;

        else if (*p == '>')

            skip = 0;

        else if (p[0] == '\n' && p[1])

            av_bprintf(buf, "\\N");

        else if (!skip && *p != '\r')

            av_bprint_chars(buf, *p, 1);

        p++;

    }

    return 0;

}
