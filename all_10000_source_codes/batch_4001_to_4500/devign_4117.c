/* 
 * Benchmark Sample ID : devign_4117
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=77e4743c94d2a926623e280913e05ad6c840791e
 */

void scsi_req_build_sense(SCSIRequest *req, SCSISense sense)

{

    trace_scsi_req_build_sense(req->dev->id, req->lun, req->tag,

                               sense.key, sense.asc, sense.ascq);

    memset(req->sense, 0, 18);

    req->sense[0] = 0xf0;

    req->sense[2] = sense.key;

    req->sense[7] = 10;

    req->sense[12] = sense.asc;

    req->sense[13] = sense.ascq;

    req->sense_len = 18;

}
