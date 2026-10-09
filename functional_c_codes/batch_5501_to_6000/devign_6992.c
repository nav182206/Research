/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6992
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5e715b583dab85735660b15a8d217a69164675fe
 */

static int parse_metadata_ext(DBEContext *s)

{

    if (s->mtd_ext_size)

        skip_input(s, s->key_present + s->mtd_ext_size + 1);

    return 0;

}
