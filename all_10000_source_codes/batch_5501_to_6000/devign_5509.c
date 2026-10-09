/* 
 * Benchmark Sample ID : devign_5509
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5a3d7b23ba41b4884b43b6bc936ea18f999d5c6b
 */

static void xics_reset(DeviceState *d)

{

    XICSState *icp = XICS(d);

    int i;



    for (i = 0; i < icp->nr_servers; i++) {

        device_reset(DEVICE(&icp->ss[i]));

    }



    device_reset(DEVICE(icp->ics));

}
