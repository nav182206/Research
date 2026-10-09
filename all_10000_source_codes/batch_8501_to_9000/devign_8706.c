/* 
 * Benchmark Sample ID : devign_8706
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static void alloc_aio_bitmap(BlkMigDevState *bmds)

{

    BlockDriverState *bs = bmds->bs;

    int64_t bitmap_size;



    bitmap_size = bdrv_nb_sectors(bs) + BDRV_SECTORS_PER_DIRTY_CHUNK * 8 - 1;

    bitmap_size /= BDRV_SECTORS_PER_DIRTY_CHUNK * 8;



    bmds->aio_bitmap = g_malloc0(bitmap_size);

}
