/* 
 * Benchmark Sample ID : devign_2338
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2da0d70d5eebe42f9fcd27ee554419ebe2a5da06
 */

static inline void RENAME(yuv2nv12X)(SwsContext *c, int16_t *lumFilter, int16_t **lumSrc, int lumFilterSize,

				     int16_t *chrFilter, int16_t **chrSrc, int chrFilterSize,

				     uint8_t *dest, uint8_t *uDest, int dstW, int chrDstW, int dstFormat)

{

yuv2nv12XinC(lumFilter, lumSrc, lumFilterSize,

	     chrFilter, chrSrc, chrFilterSize,

	     dest, uDest, dstW, chrDstW, dstFormat);

}
