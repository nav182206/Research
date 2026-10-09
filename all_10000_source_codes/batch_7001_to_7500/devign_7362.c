/* 
 * Benchmark Sample ID : devign_7362
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7cbb32e461cdbe8b745d560c1700c711ba5933cc
 */

static double block_angle(int x, int y, int cx, int cy, MotionVector *shift)

{

    double a1, a2, diff;



    a1 = atan2(y - cy, x - cx);

    a2 = atan2(y - cy + shift->y, x - cx + shift->x);



    diff = a2 - a1;



    return (diff > M_PI)  ? diff - 2 * M_PI :

           (diff < -M_PI) ? diff + 2 * M_PI :

           diff;

}
