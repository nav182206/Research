/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_919
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=cf818be4f2f1e06bf63da3a6b55a4c3620952070
 */

static int make_ydt24_entry(int p1, int p2, int16_t *ydt)

{

    int lo, hi;



    lo = ydt[p1];

    hi = ydt[p2];

    return (lo + (hi << 8) + (hi << 16)) << 1;

}
