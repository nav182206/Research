/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9180
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1acd7d594c15aa491729c837ad3519d3469e620a
 */

static void FUNCC(pred8x8_horizontal_add)(uint8_t *pix, const int *block_offset,

                                          const int16_t *block,

                                          ptrdiff_t stride)

{

    int i;

    for(i=0; i<4; i++)

        FUNCC(pred4x4_horizontal_add)(pix + block_offset[i], block + i*16*sizeof(pixel), stride);

}
