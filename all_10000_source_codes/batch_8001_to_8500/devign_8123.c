/* 
 * Benchmark Sample ID : devign_8123
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=32ac63ee10ca5daa149344a75d736c1b98177392
 */

static inline int decode_mb(MDECContext *a, DCTELEM block[6][64]){

    int i;

    const int block_index[6]= {5,4,0,1,2,3};



    a->dsp.clear_blocks(block[0]);



    for(i=0; i<6; i++){

        if( mdec_decode_block_intra(a, block[ block_index[i] ], block_index[i]) < 0)

            return -1;

    }

    return 0;

}
