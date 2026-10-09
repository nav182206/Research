/* 
 * Benchmark Sample ID : devign_9765
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2ef0f392711445e173a56b2c073dedb021ae3783
 */

static int rac_get_model_sym(RangeCoder *c, Model *m)

{

    int prob, prob2, helper, val;

    int end, end2;



    prob       = 0;

    prob2      = c->range;

    c->range >>= MODEL_SCALE;

    val        = 0;

    end        = m->num_syms >> 1;

    end2       = m->num_syms;

    do {

        helper = m->freqs[end] * c->range;

        if (helper <= c->low) {

            val   = end;

            prob  = helper;

        } else {

            end2  = end;

            prob2 = helper;

        }

        end = (end2 + val) >> 1;

    } while (end != val);

    c->low  -= prob;

    c->range = prob2 - prob;

    if (c->range < RAC_BOTTOM)

        rac_normalise(c);



    model_update(m, val);



    return val;

}
