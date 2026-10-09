/* 
 * Benchmark Sample ID : devign_6403
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=30ca440eec9fe1d7eec5a48addac656438778278
 */

static QOSState *pci_test_start(int socket)

{

    const char *cmd = "-netdev socket,fd=%d,id=hs0 -device "

                      "virtio-net-pci,netdev=hs0";



    return qtest_pc_boot(cmd, socket);

}
