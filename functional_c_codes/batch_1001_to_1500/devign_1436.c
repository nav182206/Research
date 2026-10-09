/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1436
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd269ebc82fbaa5fe7ce5bc7c1770ac8acecd884
 */

void tcp_start_incoming_migration(const char *host_port, Error **errp)

{

    Error *err = NULL;

    SocketAddressLegacy *saddr = tcp_build_address(host_port, &err);

    if (!err) {

        socket_start_incoming_migration(saddr, &err);

    }

    error_propagate(errp, err);

}
