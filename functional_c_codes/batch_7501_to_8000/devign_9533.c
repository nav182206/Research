/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9533
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=636ced8e1dc8248a1353b416240b93d70ad03edb
 */

static void probe_group_enter(const char *name, int type)

{

    int64_t count = -1;



    octx.prefix =

        av_realloc(octx.prefix, sizeof(PrintElement) * (octx.level + 1));



    if (!octx.prefix || !name) {

        fprintf(stderr, "Out of memory\n");

        exit(1);

    }



    if (octx.level) {

        PrintElement *parent = octx.prefix + octx.level -1;

        if (parent->type == ARRAY)

            count = parent->nb_elems;

        parent->nb_elems++;

    }



    octx.prefix[octx.level++] = (PrintElement){name, type, count, 0};

}
