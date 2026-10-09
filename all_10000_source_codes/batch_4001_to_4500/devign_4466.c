/* 
 * Benchmark Sample ID : devign_4466
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3e9fab690d59ac15956c3733fe0794ce1ae4c4af
 */

void hmp_block_set_io_throttle(Monitor *mon, const QDict *qdict)

{

    Error *err = NULL;



    qmp_block_set_io_throttle(qdict_get_str(qdict, "device"),

                              qdict_get_int(qdict, "bps"),

                              qdict_get_int(qdict, "bps_rd"),

                              qdict_get_int(qdict, "bps_wr"),

                              qdict_get_int(qdict, "iops"),

                              qdict_get_int(qdict, "iops_rd"),

                              qdict_get_int(qdict, "iops_wr"), &err);

    hmp_handle_error(mon, &err);

}
