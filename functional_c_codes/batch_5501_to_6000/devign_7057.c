/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7057
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=428098165de4c3edfe42c1b7f00627d287015863
 */

static int div_round (int dividend, int divisor)

{

    if (dividend > 0)

	return (dividend + (divisor>>1)) / divisor;

    else

	return -((-dividend + (divisor>>1)) / divisor);

}
