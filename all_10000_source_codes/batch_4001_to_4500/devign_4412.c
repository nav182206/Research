/* 
 * Benchmark Sample ID : devign_4412
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

void bdrv_add_before_write_notifier(BlockDriverState *bs,

                                    NotifierWithReturn *notifier)

{

    notifier_with_return_list_add(&bs->before_write_notifiers, notifier);

}
