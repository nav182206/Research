/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7852
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6c0107822d3ed7588fa857c3ed1ee886b4ba62e9
 */

static int diff_C(unsigned char *old, unsigned char *new, int os, int ns)

{

    int x, y, d=0;

    for (y = 8; y; y--) {

        for (x = 8; x; x--) {

            d += abs(new[x] - old[x]);

        }

        new += ns;

        old += os;

    }

    return d;

}
