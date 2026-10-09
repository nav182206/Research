/* 
 * Benchmark Sample ID : devign_5288
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=61e68b3fbd3e2b7beb636bc56f78d9c1ca25e8f9
 */

void scsi_req_unref(SCSIRequest *req)

{

    assert(req->refcount > 0);

    if (--req->refcount == 0) {

        BusState *qbus = req->dev->qdev.parent_bus;

        SCSIBus *bus = DO_UPCAST(SCSIBus, qbus, qbus);



        if (bus->info->free_request && req->hba_private) {

            bus->info->free_request(bus, req->hba_private);

        }

        if (req->ops->free_req) {

            req->ops->free_req(req);

        }

        object_unref(OBJECT(req->dev));

        object_unref(OBJECT(qbus->parent));

        g_free(req);

    }

}
