/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5514
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=debaaa114a8877a939533ba846e64168fb287b7b
 */

static void test_io_rw_interface(enum AddrMode lba48, enum IOMode dma,

                                 unsigned bufsize, uint64_t sector)

{

    AHCIQState *ahci;



    ahci = ahci_boot_and_enable();

    ahci_test_io_rw_simple(ahci, bufsize, sector,

                           io_cmds[dma][lba48][IO_READ],

                           io_cmds[dma][lba48][IO_WRITE]);

    ahci_shutdown(ahci);

}
