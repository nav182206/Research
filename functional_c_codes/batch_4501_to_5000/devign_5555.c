/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5555
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=be9ce6e10a8d53b8bc346c9337d75a5a30631a2a
 */

static void mov_parse_stsd_subtitle(MOVContext *c, AVIOContext *pb,

                                    AVStream *st, MOVStreamContext *sc,

                                    int size)

{

    // ttxt stsd contains display flags, justification, background

    // color, fonts, and default styles, so fake an atom to read it

    MOVAtom fake_atom = { .size = size };

    // mp4s contains a regular esds atom

    if (st->codec->codec_tag != AV_RL32("mp4s"))

        mov_read_glbl(c, pb, fake_atom);

    st->codec->width  = sc->width;

    st->codec->height = sc->height;

}
