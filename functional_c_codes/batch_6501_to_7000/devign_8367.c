/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8367
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c23acbaed40101c677dfcfbbfe0d2c230a8e8f44
 */

static void add_pixels_clamped4_c(const DCTELEM *block, uint8_t *restrict pixels,

                          int line_size)

{

    int i;

    uint8_t *cm = ff_cropTbl + MAX_NEG_CROP;



    /* read the pixels */

    for(i=0;i<4;i++) {

        pixels[0] = cm[pixels[0] + block[0]];

        pixels[1] = cm[pixels[1] + block[1]];

        pixels[2] = cm[pixels[2] + block[2]];

        pixels[3] = cm[pixels[3] + block[3]];

        pixels += line_size;

        block += 8;

    }

}
