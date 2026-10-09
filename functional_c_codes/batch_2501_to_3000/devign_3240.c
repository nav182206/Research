/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3240
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0ecca7a49f8e254c12a3a1de048d738bfbb614c6
 */

int match_ext(const char *filename, const char *extensions)

{

    const char *ext, *p;

    char ext1[32], *q;



    if(!filename)

        return 0;

    

    ext = strrchr(filename, '.');

    if (ext) {

        ext++;

        p = extensions;

        for(;;) {

            q = ext1;

            while (*p != '\0' && *p != ',') 

                *q++ = *p++;

            *q = '\0';

            if (!strcasecmp(ext1, ext)) 

                return 1;

            if (*p == '\0') 

                break;

            p++;

        }

    }

    return 0;

}
