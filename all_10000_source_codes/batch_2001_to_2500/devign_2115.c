/* 
 * Benchmark Sample ID : devign_2115
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=141f03541b39e131a5e8aa776a88abe77b70618e
 */

int av_set_options_string(void *ctx, const char *opts,

                          const char *key_val_sep, const char *pairs_sep)

{

    int ret, count = 0;





    while (*opts) {

        if ((ret = parse_key_value_pair(ctx, &opts, key_val_sep, pairs_sep)) < 0)

            return ret;

        count++;



        if (*opts)

            opts++;

    }



    return count;

}
