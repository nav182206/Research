/* 
 * Benchmark Sample ID : devign_1967
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2898bc522da6adebda5cbbd9036defe22e3b9bcf
 */

void FUNCC(ff_h264_chroma_dc_dequant_idct)(int16_t *_block, int qmul){

    const int stride= 16*2;

    const int xStride= 16;

    int a,b,c,d,e;

    dctcoef *block = (dctcoef*)_block;



    a= block[stride*0 + xStride*0];

    b= block[stride*0 + xStride*1];

    c= block[stride*1 + xStride*0];

    d= block[stride*1 + xStride*1];



    e= a-b;

    a= a+b;

    b= c-d;

    c= c+d;



    block[stride*0 + xStride*0]= ((a+c)*qmul) >> 7;

    block[stride*0 + xStride*1]= ((e+b)*qmul) >> 7;

    block[stride*1 + xStride*0]= ((a-c)*qmul) >> 7;

    block[stride*1 + xStride*1]= ((e-b)*qmul) >> 7;

}
