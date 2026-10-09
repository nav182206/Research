/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9243
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=624cdd46d7f67fa2d23e87ffe0a36a569edde11a
 */

static void vnc_init_basic_info_from_server_addr(QIOChannelSocket *ioc,
                                                 VncBasicInfo *info,
                                                 Error **errp)
{
    SocketAddress *addr = NULL;
    addr = qio_channel_socket_get_local_address(ioc, errp);
    if (!addr) {
    vnc_init_basic_info(addr, info, errp);
    qapi_free_SocketAddress(addr);
