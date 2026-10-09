/* 
 * Benchmark Sample ID : devign_7423
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0719e71e5297f68b6b4500aa74e1b49d59806342
 */

static bool sd_get_inserted(SDState *sd)

{

    return blk_is_inserted(sd->blk);

}
