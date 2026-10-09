/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_722
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=13a099799e89a76eb921ca452e1b04a7a28a9855
 */

yuv2gray16_1_c_template(SwsContext *c, const uint16_t *buf0,

                        const uint16_t *ubuf0, const uint16_t *ubuf1,

                        const uint16_t *vbuf0, const uint16_t *vbuf1,

                        const uint16_t *abuf0, uint8_t *dest, int dstW,

                        int uvalpha, enum PixelFormat dstFormat,

                        int flags, int y, enum PixelFormat target)

{

    int i;



    for (i = 0; i < (dstW >> 1); i++) {

        const int i2 = 2 * i;

        int Y1 = buf0[i2  ] << 1;

        int Y2 = buf0[i2+1] << 1;



        output_pixel(&dest[2 * i2 + 0], Y1);

        output_pixel(&dest[2 * i2 + 2], Y2);

    }

}
