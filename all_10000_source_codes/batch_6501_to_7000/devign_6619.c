/* 
 * Benchmark Sample ID : devign_6619
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9a8a5ae69d3a436e51a7eb2edafe254572f60823
 */

static char *tcg_get_arg_str_idx(TCGContext *s, char *buf, int buf_size,

                                 int idx)

{

    TCGTemp *ts;



    assert(idx >= 0 && idx < s->nb_temps);

    ts = &s->temps[idx];

    assert(ts);

    if (idx < s->nb_globals) {

        pstrcpy(buf, buf_size, ts->name);

    } else {

        if (ts->temp_local) 

            snprintf(buf, buf_size, "loc%d", idx - s->nb_globals);

        else

            snprintf(buf, buf_size, "tmp%d", idx - s->nb_globals);

    }

    return buf;

}
