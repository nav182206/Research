/* 
 * Benchmark Sample ID : devign_2656
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5a7bd28335d502d90c727f69a50e6f251c305e72
 */

void align_get_bits(GetBitContext *s)

{

    int n= (-get_bits_count(s)) & 7;

    if(n) skip_bits(s, n);

}
