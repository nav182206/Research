/* 
 * Benchmark Sample ID : devign_6718
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=86ab6b6e08e2982fb5785e0691c0a7e289339ffb
 */

static int decode_value(SCPRContext *s, unsigned *cnt, unsigned maxc, unsigned step, unsigned *rval)

{

    GetByteContext *gb = &s->gb;

    RangeCoder *rc = &s->rc;

    unsigned totfr = cnt[maxc];

    unsigned value;

    unsigned c = 0, cumfr = 0, cnt_c = 0;

    int i, ret;



    if ((ret = s->get_freq(rc, totfr, &value)) < 0)

        return ret;



    while (c < maxc) {

        cnt_c = cnt[c];

        if (value >= cumfr + cnt_c)

            cumfr += cnt_c;

        else

            break;

        c++;

    }

    s->decode(gb, rc, cumfr, cnt_c, totfr);



    cnt[c] = cnt_c + step;

    totfr += step;

    if (totfr > BOT) {

        totfr = 0;

        for (i = 0; i < maxc; i++) {

            unsigned nc = (cnt[i] >> 1) + 1;

            cnt[i] = nc;

            totfr += nc;

        }

    }



    cnt[maxc] = totfr;

    *rval = c;



    return 0;

}
