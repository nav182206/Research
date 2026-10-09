/* 
 * Benchmark Sample ID : devign_5654
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

static void coroutine_fn bdrv_discard_co_entry(void *opaque)

{

    DiscardCo *rwco = opaque;



    rwco->ret = bdrv_co_discard(rwco->bs, rwco->sector_num, rwco->nb_sectors);

}
