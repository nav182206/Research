/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2042
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=92cb05574b7bd489be81f9c58497dc7dfe5d8859
 */

bool virtio_disk_is_scsi(void)

{

    if (guessed_disk_nature) {

        return (blk_cfg.blk_size  == 512);

    }

    return (blk_cfg.geometry.heads == 255)

        && (blk_cfg.geometry.sectors == 63)

        && (blk_cfg.blk_size  == 512);

}
