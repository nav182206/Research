/* 
 * Benchmark Sample ID : devign_7571
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8b33d9eeba91422ee2d73b6936ad57262d18cf5a
 */

static int raw_write_scrubbed_bootsect(BlockDriverState *bs,

                                       const uint8_t *buf)

{

    uint8_t bootsect[512];



    /* scrub the dangerous signature */

    memcpy(bootsect, buf, 512);

    memset(bootsect, 0, 4);



    return bdrv_write(bs->file, 0, bootsect, 1);

}
