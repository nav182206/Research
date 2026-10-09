/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1437
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=83fd377c94d8fbffdb3e69fb3efe1976ff897a88
 */

static void init_quantization(Jpeg2000EncoderContext *s)

{

    int compno, reslevelno, bandno;

    Jpeg2000QuantStyle  *qntsty = &s->qntsty;

    Jpeg2000CodingStyle *codsty = &s->codsty;



    for (compno = 0; compno < s->ncomponents; compno++){

        int gbandno = 0;

        for (reslevelno = 0; reslevelno < codsty->nreslevels; reslevelno++){

            int nbands, lev = codsty->nreslevels - reslevelno - 1;

            nbands = reslevelno ? 3 : 1;

            for (bandno = 0; bandno < nbands; bandno++, gbandno++){

                int expn, mant;



                if (codsty->transform == FF_DWT97){

                    int bandpos = bandno + (reslevelno>0),

                        ss = 81920000 / dwt_norms[0][bandpos][lev],

                        log = av_log2(ss);

                    mant = (11 - log < 0 ? ss >> log - 11 : ss << 11 - log) & 0x7ff;

                    expn = s->cbps[compno] - log + 13;

                } else

                    expn = ((bandno&2)>>1) + (reslevelno>0) + s->cbps[compno];



                qntsty->expn[gbandno] = expn;

                qntsty->mant[gbandno] = mant;

            }

        }

    }

}
