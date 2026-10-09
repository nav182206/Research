/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_424
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f92f4935acd7d974adfd1deebdf1bb06cbe107ca
 */

static uint32_t add_weights(uint32_t w1, uint32_t w2)

{

    uint32_t max = (w1 & 0xFF) > (w2 & 0xFF) ? (w1 & 0xFF) : (w2 & 0xFF);



    return ((w1 & 0xFFFFFF00) + (w2 & 0xFFFFFF00)) | (1 + max);

}
