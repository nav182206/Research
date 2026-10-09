/* 
 * Benchmark Sample ID : devign_9288
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c6c0e513600ba57c3e73b7151d3c0664438f7b5
 */

static void vscsi_send_request_sense(VSCSIState *s, vscsi_req *req)

{

    SCSIDevice *sdev = req->sdev;

    uint8_t *cdb = req->iu.srp.cmd.cdb;

    int n;



    cdb[0] = 3;

    cdb[1] = 0;

    cdb[2] = 0;

    cdb[3] = 0;

    cdb[4] = 96;

    cdb[5] = 0;

    req->sensing = 1;

    n = sdev->info->send_command(sdev, req->qtag, cdb, req->lun);

    dprintf("VSCSI: Queued request sense tag 0x%x\n", req->qtag);

    if (n < 0) {

        fprintf(stderr, "VSCSI: REQUEST_SENSE wants write data !?!?!?\n");

        sdev->info->cancel_io(sdev, req->qtag);

        vscsi_makeup_sense(s, req, HARDWARE_ERROR, 0, 0);

        vscsi_send_rsp(s, req, CHECK_CONDITION, 0, 0);

        vscsi_put_req(s, req);

        return;

    } else if (n == 0) {

        return;

    }

    sdev->info->read_data(sdev, req->qtag);

}
