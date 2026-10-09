/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8648
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=16f753f43fba3b9b16cb9fa62e99f481aaa29ae9
 */

static int flac_probe(AVProbeData *p)

{

    uint8_t *bufptr = p->buf;



    if(ff_id3v2_match(bufptr))

        bufptr += ff_id3v2_tag_len(bufptr);



    if(memcmp(bufptr, "fLaC", 4)) return 0;

    else                          return AVPROBE_SCORE_MAX / 2;

}
