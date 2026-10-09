/* 
 * Benchmark Sample ID : devign_8378
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1d16a1cf99488f16492b1bb48e023f4da8377e07
 */

static void ff_h264_idct_add8_mmx(uint8_t **dest, const int *block_offset, DCTELEM *block, int stride, const uint8_t nnzc[6*8]){

    int i;

    for(i=16; i<16+8; i++){

        if(nnzc[ scan8[i] ] || block[i*16])

            ff_h264_idct_add_mmx    (dest[(i&4)>>2] + block_offset[i], block + i*16, stride);

    }

}
