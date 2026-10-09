/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3333
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=579795b2049bc8b0f291b302e7ab24f9561eaf24
 */

static int get_channel_idx(char **map, int *ch, char delim, int max_ch)

{

    char *next = split(*map, delim);

    int len;

    int n = 0;

    if (!next && delim == '-')




    len = strlen(*map);

    sscanf(*map, "%d%n", ch, &n);

    if (n != len)


    if (*ch < 0 || *ch > max_ch)


    *map = next;

    return 0;

}
