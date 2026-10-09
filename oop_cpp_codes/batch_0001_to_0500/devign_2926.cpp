/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2926
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f51074cdc6e750daa3b6df727d83449a7e42b391
 */

DriveInfo *add_init_drive(const char *optstr)

{

    DriveInfo *dinfo;

    QemuOpts *opts;

    MachineClass *mc;



    opts = drive_def(optstr);

    if (!opts)

        return NULL;



    mc = MACHINE_GET_CLASS(current_machine);

    dinfo = drive_new(opts, mc->block_default_type);

    if (!dinfo) {

        qemu_opts_del(opts);

        return NULL;

    }



    return dinfo;

}
