/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1803
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1d16a1cf99488f16492b1bb48e023f4da8377e07
 */

static void ff_h264_idct8_add4_mmx2(uint8_t *dst, const int *block_offset, DCTELEM *block, int stride, const uint8_t nnzc[6*8]){

    int i;

    for(i=0; i<16; i+=4){

        int nnz = nnzc[ scan8[i] ];

        if(nnz){

            if(nnz==1 && block[i*16]) ff_h264_idct8_dc_add_mmx2(dst + block_offset[i], block + i*16, stride);

            else                      ff_h264_idct8_add_mmx    (dst + block_offset[i], block + i*16, stride);

        }

    }

}
