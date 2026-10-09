/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1039
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1d16a1cf99488f16492b1bb48e023f4da8377e07
 */

static void ff_h264_idct_add8_mmx2(uint8_t **dest, const int *block_offset, DCTELEM *block, int stride, const uint8_t nnzc[6*8]){

    int i;

    for(i=16; i<16+8; i++){

        if(nnzc[ scan8[i] ])

            ff_h264_idct_add_mmx    (dest[(i&4)>>2] + block_offset[i], block + i*16, stride);

        else if(block[i*16])

            ff_h264_idct_dc_add_mmx2(dest[(i&4)>>2] + block_offset[i], block + i*16, stride);

    }

}
