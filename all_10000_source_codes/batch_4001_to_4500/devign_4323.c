/* 
 * Benchmark Sample ID : devign_4323
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ae50b2747f77944faa79eb914272b54eb30b63b3
 */

VLANClientState *qdev_get_vlan_client(DeviceState *dev,

                                      NetCanReceive *can_receive,

                                      NetReceive *receive,

                                      NetReceiveIOV *receive_iov,

                                      NetCleanup *cleanup,

                                      void *opaque)

{

    NICInfo *nd = dev->nd;

    assert(nd);

    return qemu_new_vlan_client(nd->vlan, nd->model, nd->name, can_receive,

                                receive, receive_iov, cleanup, opaque);

}
