/* 
 * Benchmark Sample ID : devign_1293
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static void qemu_rdma_dump_gid(const char *who, struct rdma_cm_id *id)

{

    char sgid[33];

    char dgid[33];

    inet_ntop(AF_INET6, &id->route.addr.addr.ibaddr.sgid, sgid, sizeof sgid);

    inet_ntop(AF_INET6, &id->route.addr.addr.ibaddr.dgid, dgid, sizeof dgid);

    DPRINTF("%s Source GID: %s, Dest GID: %s\n", who, sgid, dgid);

}
