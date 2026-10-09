/* 
 * Benchmark Sample ID : devign_2996
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1ba08c94f5bb4d1c3c2d3651b5e01edb4ce172e2
 */

static inline void put_codeword(PutBitContext *pb, vorbis_enc_codebook *cb,

                                int entry)

{

    assert(entry >= 0);

    assert(entry < cb->nentries);

    assert(cb->lens[entry]);

    put_bits(pb, cb->lens[entry], cb->codewords[entry]);

}
