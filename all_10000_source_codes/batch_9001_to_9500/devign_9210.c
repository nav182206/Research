/* 
 * Benchmark Sample ID : devign_9210
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=568e18b15e2ddf494fd8926707d34ca08c8edce5
 */

static uint64_t get_vb(ByteIOContext *bc){

    uint64_t val=0;

    int i= get_v(bc);

    

    if(i>8)

        return UINT64_MAX;

    

    while(i--)

        val = (val<<8) + get_byte(bc);

    

//av_log(NULL, AV_LOG_DEBUG, "get_vb()= %lld\n", val);

    return val;

}
