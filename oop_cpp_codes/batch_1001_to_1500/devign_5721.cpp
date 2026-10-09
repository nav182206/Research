/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5721
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a818a4b69d47ca3826dee36878074395aeac2083
 */

static void scsi_cd_class_initfn(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);

    SCSIDeviceClass *sc = SCSI_DEVICE_CLASS(klass);



    sc->init         = scsi_cd_initfn;

    sc->destroy      = scsi_destroy;

    sc->alloc_req    = scsi_new_request;

    sc->unit_attention_reported = scsi_disk_unit_attention_reported;

    dc->fw_name = "disk";

    dc->desc = "virtual SCSI CD-ROM";

    dc->reset = scsi_disk_reset;

    dc->props = scsi_cd_properties;

    dc->vmsd  = &vmstate_scsi_disk_state;

}
