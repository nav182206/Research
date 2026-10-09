/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3478
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9cf0419bb1a2cf929dcf458d435ae3c3bfb5d3ab
 */

static int mov_read_moov(MOVContext *c, ByteIOContext *pb, MOV_atom_t atom)

{

    int err;



    err = mov_read_default(c, pb, atom);

    /* we parsed the 'moov' atom, we can terminate the parsing as soon as we find the 'mdat' */

    /* so we don't parse the whole file if over a network */

    c->found_moov=1;

    if(c->found_mdat)

        return 1; /* found both, just go */

    return 0; /* now go for mdat */

}
