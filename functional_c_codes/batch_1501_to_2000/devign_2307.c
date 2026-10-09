/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2307
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

void *qemu_blockalign0(BlockDriverState *bs, size_t size)

{

    return memset(qemu_blockalign(bs, size), 0, size);

}
