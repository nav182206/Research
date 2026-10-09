/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_1387
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2e2aa31674444b61e79536a90d63a90572e695c8
 */

static void mptsas_scsi_uninit(PCIDevice *dev)

{

    MPTSASState *s = MPT_SAS(dev);



    qemu_bh_delete(s->request_bh);

    if (s->msi_in_use) {

        msi_uninit(dev);

    }

}
