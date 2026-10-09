/* 
 * Benchmark Sample ID : devign_4791
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e6bc38fd49c94726b45d5d5cc2b756ad8ec49ee0
 */

void ff_wmv2_idct_c(short * block){

    int i;



    for(i=0;i<64;i+=8){

        wmv2_idct_row(block+i);

    }

    for(i=0;i<8;i++){

        wmv2_idct_col(block+i);

    }

}
