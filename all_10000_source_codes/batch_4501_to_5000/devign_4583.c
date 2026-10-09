/* 
 * Benchmark Sample ID : devign_4583
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=debaaa114a8877a939533ba846e64168fb287b7b
 */

static void test_flush(void)

{

    AHCIQState *ahci;



    ahci = ahci_boot_and_enable();

    ahci_test_flush(ahci);

    ahci_shutdown(ahci);

}
