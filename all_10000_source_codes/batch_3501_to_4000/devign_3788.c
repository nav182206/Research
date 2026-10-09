/* 
 * Benchmark Sample ID : devign_3788
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2caf19e90f270abe1e80a3e85acaf0eb5c9d0aac
 */

static void FUNCC(pred4x4_129_dc)(uint8_t *_src, const uint8_t *topright, int _stride){

    pixel *src = (pixel*)_src;

    int stride = _stride/sizeof(pixel);

    ((pixel4*)(src+0*stride))[0]=

    ((pixel4*)(src+1*stride))[0]=

    ((pixel4*)(src+2*stride))[0]=

    ((pixel4*)(src+3*stride))[0]= PIXEL_SPLAT_X4((1<<(BIT_DEPTH-1))+1);

}
