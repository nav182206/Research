/* 
 * Benchmark Sample ID : devign_4824
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=98fdfa99704f1cfef3d3a26c580b92749b6b64cb
 */

static void get_pixels_altivec(int16_t *restrict block, const uint8_t *pixels, int line_size)

{

    int i;

    vector unsigned char perm = vec_lvsl(0, pixels);

    vector unsigned char bytes;

    const vector unsigned char zero = (const vector unsigned char)vec_splat_u8(0);

    vector signed short shorts;



    for (i = 0; i < 8; i++) {

        // Read potentially unaligned pixels.

        // We're reading 16 pixels, and actually only want 8,

        // but we simply ignore the extras.

        vector unsigned char pixl = vec_ld( 0, pixels);

        vector unsigned char pixr = vec_ld(15, pixels);

        bytes = vec_perm(pixl, pixr, perm);



        // convert the bytes into shorts

        shorts = (vector signed short)vec_mergeh(zero, bytes);



        // save the data to the block, we assume the block is 16-byte aligned

        vec_st(shorts, i*16, (vector signed short*)block);



        pixels += line_size;

    }

}
