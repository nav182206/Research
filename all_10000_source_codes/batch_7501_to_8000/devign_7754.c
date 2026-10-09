/* 
 * Benchmark Sample ID : devign_7754
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static int ssi_sd_init(SSISlave *d)

{

    DeviceState *dev = DEVICE(d);

    ssi_sd_state *s = FROM_SSI_SLAVE(ssi_sd_state, d);

    DriveInfo *dinfo;



    s->mode = SSI_SD_CMD;

    dinfo = drive_get_next(IF_SD);

    s->sd = sd_init(dinfo ? blk_bs(blk_by_legacy_dinfo(dinfo)) : NULL, true);

    if (s->sd == NULL) {

        return -1;

    }

    register_savevm(dev, "ssi_sd", -1, 1, ssi_sd_save, ssi_sd_load, s);

    return 0;

}
