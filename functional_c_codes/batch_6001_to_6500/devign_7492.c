/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7492
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=69e7336b8e16ee65226fc20381baf537f4b125e6
 */

static int match_format(const char *name, const char *names)

{

    const char *p;

    int len, namelen;



    if (!name || !names)

        return 0;



    namelen = strlen(name);

    while ((p = strchr(names, ','))) {

        len = FFMAX(p - names, namelen);

        if (!av_strncasecmp(name, names, len))

            return 1;

        names = p + 1;

    }

    return !av_strcasecmp(name, names);

}
