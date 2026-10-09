/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1484
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5e715b583dab85735660b15a8d217a69164675fe
 */

static int parse_key(DBEContext *s)

{

    int key = 0;



    if (s->key_present && s->input_size > 0)

        key = AV_RB24(s->input) >> 24 - s->word_bits;



    skip_input(s, s->key_present);

    return key;

}
