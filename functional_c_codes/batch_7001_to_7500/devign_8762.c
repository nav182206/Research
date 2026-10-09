/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8762
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8b33d9eeba91422ee2d73b6936ad57262d18cf5a
 */

static int check_write_unsafe(BlockDriverState *bs, int64_t sector_num,

                              const uint8_t *buf, int nb_sectors)

{

    /* assume that if the user specifies the format explicitly, then assume

       that they will continue to do so and provide no safety net */

    if (!bs->probed) {

        return 0;

    }



    if (sector_num == 0 && nb_sectors > 0) {

        return check_for_block_signature(bs, buf);

    }



    return 0;

}
