/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2632
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8176bd1a4689ff08b0e85984563ad8288110f1a7
 */

static uint64_t log16(uint64_t a){

    int i;

    int out=0;

    

    assert(a >= (1<<16));

    a<<=16;

    

    for(i=19;i>=0;i--){

        if(a<(exp16_table[i]<<16)) continue;

        out |= 1<<i;

        a = ((a<<16) + exp16_table[i]/2)/exp16_table[i];

    }

    return out;

}
