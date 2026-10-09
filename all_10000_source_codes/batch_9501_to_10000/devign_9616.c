/* 
 * Benchmark Sample ID : devign_9616
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

static inline bool bdrv_req_is_aligned(BlockDriverState *bs,

                                       int64_t offset, size_t bytes)

{

    int64_t align = bdrv_get_align(bs);

    return !(offset & (align - 1) || (bytes & (align - 1)));

}
