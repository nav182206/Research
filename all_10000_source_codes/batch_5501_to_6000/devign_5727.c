/* 
 * Benchmark Sample ID : devign_5727
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dfd100f242370886bb6732f70f1f7cbd8eb9fedc
 */

static void vnc_init_basic_info_from_remote_addr(QIOChannelSocket *ioc,

                                                 VncBasicInfo *info,

                                                 Error **errp)

{

    SocketAddress *addr = NULL;



    addr = qio_channel_socket_get_remote_address(ioc, errp);

    if (!addr) {

        return;

    }



    vnc_init_basic_info(addr, info, errp);

    qapi_free_SocketAddress(addr);

}
