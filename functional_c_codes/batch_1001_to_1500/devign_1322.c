/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1322
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd269ebc82fbaa5fe7ce5bc7c1770ac8acecd884
 */

void unix_start_incoming_migration(const char *path, Error **errp)

{

    SocketAddressLegacy *saddr = unix_build_address(path);

    socket_start_incoming_migration(saddr, errp);

}
