/* 
 * Benchmark Sample ID : devign_4436
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f78cd0c243b9149c7f604ecf1006d78e344aa6ca
 */

void ff_simple_idct84_add(uint8_t *dest, int line_size, DCTELEM *block)

{

    int i;



    /* IDCT8 on each line */

    for(i=0; i<4; i++) {

        idctRowCondDC_8(block + i*8);

    }



    /* IDCT4 and store */

    for(i=0;i<8;i++) {

        idct4col_add(dest + i, line_size, block + i);

    }

}
