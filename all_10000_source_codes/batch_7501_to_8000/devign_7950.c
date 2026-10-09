/* 
 * Benchmark Sample ID : devign_7950
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2caf19e90f270abe1e80a3e85acaf0eb5c9d0aac
 */

static void FUNCC(pred16x16_horizontal)(uint8_t *_src, int stride){

    int i;

    pixel *src = (pixel*)_src;

    stride /= sizeof(pixel);



    for(i=0; i<16; i++){

        ((pixel4*)(src+i*stride))[0] =

        ((pixel4*)(src+i*stride))[1] =

        ((pixel4*)(src+i*stride))[2] =

        ((pixel4*)(src+i*stride))[3] = PIXEL_SPLAT_X4(src[-1+i*stride]);

    }

}
