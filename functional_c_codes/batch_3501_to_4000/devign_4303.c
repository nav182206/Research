/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4303
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c6d2283068026035a6468aae9dcde953bd7521ac
 */

void bdrv_set_dirty_tracking(BlockDriverState *bs, int enable)

{

    int64_t bitmap_size;



    if (enable) {

        if (bs->dirty_tracking == 0) {

            int64_t i;

            uint8_t test;



            bitmap_size = (bdrv_getlength(bs) >> BDRV_SECTOR_BITS);

            bitmap_size /= BDRV_SECTORS_PER_DIRTY_CHUNK;

            bitmap_size++;



            bs->dirty_bitmap = qemu_mallocz(bitmap_size);



            bs->dirty_tracking = enable;

            for(i = 0; i < bitmap_size; i++) test = bs->dirty_bitmap[i]; 

        }

    } else {

        if (bs->dirty_tracking != 0) {

            qemu_free(bs->dirty_bitmap);

            bs->dirty_tracking = enable;

        }

    }

}
