/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_87
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9be385980d37e8f4fd33f605f5fb1c3d144170a8
 */

static inline uint64_t vmdk_find_offset_in_cluster(VmdkExtent *extent,

                                                   int64_t offset)

{

    uint64_t offset_in_cluster, extent_begin_offset, extent_relative_offset;

    uint64_t cluster_size = extent->cluster_sectors * BDRV_SECTOR_SIZE;



    extent_begin_offset =

        (extent->end_sector - extent->sectors) * BDRV_SECTOR_SIZE;

    extent_relative_offset = offset - extent_begin_offset;

    offset_in_cluster = extent_relative_offset % cluster_size;



    return offset_in_cluster;

}
