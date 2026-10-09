/* 
 * Benchmark Sample ID : devign_6267
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f04db28b86654d1c7ff805b40eff27bba6b0f686
 */

uint16_t virtio_get_cylinders(void)

{

    return blk_cfg.geometry.cylinders;

}
