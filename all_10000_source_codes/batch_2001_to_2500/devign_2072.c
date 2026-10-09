/* 
 * Benchmark Sample ID : devign_2072
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2c1885adcf0312da80c7317b09f9adad97fa0fc6
 */

static inline uint32_t search_chunk(BDRVDMGState* s,int sector_num)

{

    /* binary search */

    uint32_t chunk1=0,chunk2=s->n_chunks,chunk3;

    while(chunk1!=chunk2) {

	chunk3 = (chunk1+chunk2)/2;

	if(s->sectors[chunk3]>sector_num)

	    chunk2 = chunk3;

	else if(s->sectors[chunk3]+s->sectorcounts[chunk3]>sector_num)

	    return chunk3;

	else

	    chunk1 = chunk3;

    }

    return s->n_chunks; /* error */

}
