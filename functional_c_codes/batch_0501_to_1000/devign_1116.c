/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1116
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7daabccb5d36e9bf649d157ab14ccb2a016f1c53
 */

void put_signed_pixels_clamped_mmx(const DCTELEM *block, uint8_t *pixels, int line_size)

{

    int i;

    unsigned char __align8 vector128[8] =

      { 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80 };



    movq_m2r(*vector128, mm1);

    for (i = 0; i < 8; i++) {

        movq_m2r(*(block), mm0);

        packsswb_m2r(*(block + 4), mm0);

        block += 8;

        paddb_r2r(mm1, mm0);

        movq_r2m(mm0, *pixels);

        pixels += line_size;

    }

}
