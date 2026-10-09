/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_832
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7fd1c85e51958050180b37a1bf4ce833d44f91e8
 */

static char* mpjpeg_get_boundary(AVIOContext* pb)

{

    uint8_t *mime_type = NULL;

    const char *start;

    const char *end;

    uint8_t *res = NULL;

    int     len;



    /* get MIME type, and skip to the first parameter */

    av_opt_get(pb, "mime_type", AV_OPT_SEARCH_CHILDREN, &mime_type);

    start = mime_type;

    while (start != NULL && *start != '\0') {

        start = strchr(start, ';');

        if (start)

            start = start+1;



        while (av_isspace(*start))

            start++;



        if (!av_stristart(start, "boundary=", &start)) {

            end = strchr(start, ';');

            if (end)

                len = end - start - 1;

            else

                len = strlen(start);

            res = av_strndup(start, len);

            break;

        }

    }



    av_freep(&mime_type);

    return res;

}
