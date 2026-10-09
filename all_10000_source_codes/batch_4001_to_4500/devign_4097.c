/* 
 * Benchmark Sample ID : devign_4097
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2580bae54a45d6aaf85ddc5e780389e7e90b2c86
 */

static int encode_packets(Jpeg2000EncoderContext *s, Jpeg2000Tile *tile, int tileno)

{

    int compno, reslevelno, ret;

    Jpeg2000CodingStyle *codsty = &s->codsty;

    Jpeg2000QuantStyle  *qntsty = &s->qntsty;



    av_log(s->avctx, AV_LOG_DEBUG, "tier2\n");

    // lay-rlevel-comp-pos progression

    for (reslevelno = 0; reslevelno < codsty->nreslevels; reslevelno++){

        for (compno = 0; compno < s->ncomponents; compno++){

            int precno;

            Jpeg2000ResLevel *reslevel = s->tile[tileno].comp[compno].reslevel + reslevelno;

            for (precno = 0; precno < reslevel->num_precincts_x * reslevel->num_precincts_y; precno++){

                if (ret = encode_packet(s, reslevel, precno, qntsty->expn + (reslevelno ? 3*reslevelno-2 : 0),

                              qntsty->nguardbits))

                    return ret;

            }

        }

    }

    av_log(s->avctx, AV_LOG_DEBUG, "after tier2\n");

    return 0;

}
