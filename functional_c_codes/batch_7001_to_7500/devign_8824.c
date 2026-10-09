/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8824
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0e9b9edae7bebfd31fdbead4ccbbce03876a7edd
 */

GArray *bios_linker_loader_init(void)

{

    return g_array_new(false, true /* clear */, 1);

}
