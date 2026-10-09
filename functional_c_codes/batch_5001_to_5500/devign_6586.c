/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6586
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5ed5e90f2ae299cbec66996860d794771a85fee8
 */

static int color_distance(uint32_t a, uint32_t b)

{

    int r = 0, d, i;



    for (i = 0; i < 32; i += 8) {

        d = ((a >> i) & 0xFF) - ((b >> i) & 0xFF);

        r += d * d;

    }

    return r;

}
