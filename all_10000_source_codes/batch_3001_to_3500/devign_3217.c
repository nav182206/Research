/* 
 * Benchmark Sample ID : devign_3217
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd269ebc82fbaa5fe7ce5bc7c1770ac8acecd884
 */

socket_sockaddr_to_address_vsock(struct sockaddr_storage *sa,

                                 socklen_t salen,

                                 Error **errp)

{

    SocketAddressLegacy *addr;

    VsockSocketAddress *vaddr;

    struct sockaddr_vm *svm = (struct sockaddr_vm *)sa;



    addr = g_new0(SocketAddressLegacy, 1);

    addr->type = SOCKET_ADDRESS_LEGACY_KIND_VSOCK;

    addr->u.vsock.data = vaddr = g_new0(VsockSocketAddress, 1);

    vaddr->cid = g_strdup_printf("%u", svm->svm_cid);

    vaddr->port = g_strdup_printf("%u", svm->svm_port);



    return addr;

}
