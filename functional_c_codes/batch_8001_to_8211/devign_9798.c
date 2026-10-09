/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9798
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c23acbaed40101c677dfcfbbfe0d2c230a8e8f44
 */

static void ff_jref_idct1_add(uint8_t *dest, int line_size, DCTELEM *block)

{

    uint8_t *cm = ff_cropTbl + MAX_NEG_CROP;



    dest[0] = cm[dest[0] + ((block[0] + 4)>>3)];

}
