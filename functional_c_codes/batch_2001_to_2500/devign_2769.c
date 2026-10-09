/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2769
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ce1ebb31a9a0e556a89cd7681082af19fbc1cced
 */

static unsigned tget_long(GetByteContext *gb, int le)

{

    unsigned v = le ? bytestream2_get_le32u(gb) : bytestream2_get_be32u(gb);

    return v;

}
