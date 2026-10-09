/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5876
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c3ab0004ae4dffc32494ae84dd15cfaa909a7884
 */

static inline void RENAME(nv12ToUV)(uint8_t *dstU, uint8_t *dstV,

                                    const uint8_t *src1, const uint8_t *src2,

                                    int width, uint32_t *unused)

{

    RENAME(nvXXtoUV)(dstU, dstV, src1, width);

}
