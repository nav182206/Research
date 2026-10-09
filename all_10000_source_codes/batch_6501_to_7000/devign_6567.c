/* 
 * Benchmark Sample ID : devign_6567
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8cd1c0febe88b757e915e9af15559575c21ca728
 */

static void pcx_palette(const uint8_t **src, uint32_t *dst, unsigned int pallen) {

    unsigned int i;



    for (i=0; i<pallen; i++)

        *dst++ = 0xFF000000 | bytestream_get_be24(src);

    if (pallen < 256)

        memset(dst, 0, (256 - pallen) * sizeof(*dst));

}
