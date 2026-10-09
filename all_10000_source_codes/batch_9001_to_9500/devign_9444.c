/* 
 * Benchmark Sample ID : devign_9444
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=dae7ff04160901a30a35af05f2f149b289c4f0b1
 */

static int my_log2(unsigned int i)

{

    unsigned int iLog2 = 0;

    while ((i >> iLog2) > 1)

	iLog2++;

    return iLog2;

}
