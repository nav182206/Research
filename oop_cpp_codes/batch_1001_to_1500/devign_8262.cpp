/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_8262
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fb7b5c0df6e3c501973ce4d57eb2b1d4344a519d
 */

static void scsi_device_unrealize(SCSIDevice *s, Error **errp)

{

    SCSIDeviceClass *sc = SCSI_DEVICE_GET_CLASS(s);

    if (sc->unrealize) {

        sc->unrealize(s, errp);

    }

}
