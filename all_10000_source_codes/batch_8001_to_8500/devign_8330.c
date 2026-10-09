/* 
 * Benchmark Sample ID : devign_8330
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=92cb05574b7bd489be81f9c58497dc7dfe5d8859
 */

int virtio_get_block_size(void)

{

    return blk_cfg.blk_size;

}
