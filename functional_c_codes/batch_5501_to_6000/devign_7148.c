/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7148
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c23acbaed40101c677dfcfbbfe0d2c230a8e8f44
 */

static inline void idct4col_put(uint8_t *dest, int line_size, const DCTELEM *col)

{

    int c0, c1, c2, c3, a0, a1, a2, a3;

    const uint8_t *cm = ff_cropTbl + MAX_NEG_CROP;



    a0 = col[8*0];

    a1 = col[8*2];

    a2 = col[8*4];

    a3 = col[8*6];

    c0 = ((a0 + a2) << (CN_SHIFT - 1)) + (1 << (C_SHIFT - 1));

    c2 = ((a0 - a2) << (CN_SHIFT - 1)) + (1 << (C_SHIFT - 1));

    c1 = a1 * C1 + a3 * C2;

    c3 = a1 * C2 - a3 * C1;

    dest[0] = cm[(c0 + c1) >> C_SHIFT];

    dest += line_size;

    dest[0] = cm[(c2 + c3) >> C_SHIFT];

    dest += line_size;

    dest[0] = cm[(c2 - c3) >> C_SHIFT];

    dest += line_size;

    dest[0] = cm[(c0 - c1) >> C_SHIFT];

}
