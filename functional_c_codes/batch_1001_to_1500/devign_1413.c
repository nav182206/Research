/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1413
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60f10e0ad37418cc697765d85b0bc22db70f726a
 */

static void pred8x8_left_dc_rv40_c(uint8_t *src, int stride){

    int i;

    int dc0;



    dc0=0;

    for(i=0;i<8; i++)

        dc0+= src[-1+i*stride];

    dc0= 0x01010101*((dc0 + 4)>>3);



    for(i=0; i<8; i++){

        ((uint32_t*)(src+i*stride))[0]=

        ((uint32_t*)(src+i*stride))[1]= dc0;

    }

}
