/* 
 * Benchmark Sample ID : devign_9054
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ddcd55316fb2851e144e719171621ad2816487dc
 */

static int pc_boot_set(void *opaque, const char *boot_device)

{

    return set_boot_dev(opaque, boot_device);

}
