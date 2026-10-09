/* 
 * Benchmark Sample ID : devign_4490
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=307b7715d0256c95444cada36a02882e46bada2f
 */

static void spapr_dr_connector_class_init(ObjectClass *k, void *data)

{

    DeviceClass *dk = DEVICE_CLASS(k);

    sPAPRDRConnectorClass *drck = SPAPR_DR_CONNECTOR_CLASS(k);



    dk->reset = reset;

    dk->realize = realize;

    dk->unrealize = unrealize;

    drck->set_isolation_state = set_isolation_state;

    drck->set_allocation_state = set_allocation_state;

    drck->release_pending = release_pending;

    drck->set_signalled = set_signalled;

    /*

     * Reason: it crashes FIXME find and document the real reason

     */

    dk->user_creatable = false;

}
