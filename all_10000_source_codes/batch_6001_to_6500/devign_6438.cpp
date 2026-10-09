/* 
 * Benchmark Sample ID : devign_6438
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c4d3c0a2696c09a884b680d15b03325e46656a6c
 */

static void ccw_machine_class_init(ObjectClass *oc, void *data)

{

    MachineClass *mc = MACHINE_CLASS(oc);

    NMIClass *nc = NMI_CLASS(oc);



    mc->name = "s390-ccw-virtio";

    mc->alias = "s390-ccw";

    mc->desc = "VirtIO-ccw based S390 machine";

    mc->init = ccw_init;

    mc->block_default_type = IF_VIRTIO;

    mc->no_cdrom = 1;

    mc->no_floppy = 1;

    mc->no_serial = 1;

    mc->no_parallel = 1;

    mc->no_sdcard = 1;

    mc->use_sclp = 1;

    mc->max_cpus = 255;

    mc->is_default = 1;

    nc->nmi_monitor_handler = s390_nmi;

}
