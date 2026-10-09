/* 
 * Benchmark Sample ID : devign_6922
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3d7817048cb387de87600f2152075f78b37b60a6
 */

static int can_safely_read(GetBitContext* gb, int bits) {

    return get_bits_left(gb) >= bits;

}
