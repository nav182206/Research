/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1520
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

void cpu_unregister_map_client(void *_client)

{

    MapClient *client = (MapClient *)_client;



    LIST_REMOVE(client, link);

    qemu_free(client);

}
