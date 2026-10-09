/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2705
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static char *print_drive(void *ptr)

{

    return g_strdup(bdrv_get_device_name(ptr));

}
