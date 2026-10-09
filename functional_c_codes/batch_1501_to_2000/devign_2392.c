/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2392
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=23d6bd3bd1225e8c8ade6ed829eabcf90ddfa6f7
 */

static int parallels_probe(const uint8_t *buf, int buf_size, const char *filename)

{

    const ParallelsHeader *ph = (const void *)buf;



    if (buf_size < sizeof(ParallelsHeader))

        return 0;



    if ((!memcmp(ph->magic, HEADER_MAGIC, 16) ||

        !memcmp(ph->magic, HEADER_MAGIC2, 16)) &&

        (le32_to_cpu(ph->version) == HEADER_VERSION))

        return 100;



    return 0;

}
