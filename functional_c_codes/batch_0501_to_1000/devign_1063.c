/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1063
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd269ebc82fbaa5fe7ce5bc7c1770ac8acecd884
 */

static SocketAddressLegacy *unix_build_address(const char *path)

{

    SocketAddressLegacy *saddr;



    saddr = g_new0(SocketAddressLegacy, 1);

    saddr->type = SOCKET_ADDRESS_LEGACY_KIND_UNIX;

    saddr->u.q_unix.data = g_new0(UnixSocketAddress, 1);

    saddr->u.q_unix.data->path = g_strdup(path);



    return saddr;

}
