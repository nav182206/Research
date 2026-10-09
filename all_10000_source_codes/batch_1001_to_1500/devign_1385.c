/* 
 * Benchmark Sample ID : devign_1385
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static int megasas_cache_flush(MegasasState *s, MegasasCmd *cmd)

{

    bdrv_drain_all();

    return MFI_STAT_OK;

}
