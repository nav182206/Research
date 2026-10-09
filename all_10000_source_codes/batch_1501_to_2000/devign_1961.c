/* 
 * Benchmark Sample ID : devign_1961
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9767ec6b865c35f68cb6642fefeacc009f17e638
 */

static void usage(void)

{

    printf("Escape an input string, adopting the av_get_token() escaping logic\n");

    printf("usage: ffescape [OPTIONS]\n");

    printf("\n"

           "Options:\n"

           "-e                echo each input line on output\n"

           "-h                print this help\n"

           "-i INFILE         set INFILE as input file, stdin if omitted\n"

           "-l LEVEL          set the number of escaping levels, 1 if omitted\n"

           "-m ESCAPE_MODE    select escape mode between 'full', 'lazy', 'quote', default is 'lazy'\n"

           "-o OUTFILE        set OUTFILE as output file, stdout if omitted\n"

           "-p PROMPT         set output prompt, is '=> ' by default\n"

           "-s SPECIAL_CHARS  set the list of special characters\n");

}
