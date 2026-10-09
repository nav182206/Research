/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3465
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static int bmds_aio_inflight(BlkMigDevState *bmds, int64_t sector)

{

    int64_t chunk = sector / (int64_t)BDRV_SECTORS_PER_DIRTY_CHUNK;



    if (sector < bdrv_nb_sectors(bmds->bs)) {

        return !!(bmds->aio_bitmap[chunk / (sizeof(unsigned long) * 8)] &

            (1UL << (chunk % (sizeof(unsigned long) * 8))));

    } else {

        return 0;

    }

}
