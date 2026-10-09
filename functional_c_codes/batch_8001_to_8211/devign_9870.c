/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9870
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static void cpu_notify_map_clients(void)

{

    MapClient *client;



    while (!LIST_EMPTY(&map_client_list)) {

        client = LIST_FIRST(&map_client_list);

        client->callback(client->opaque);

        cpu_unregister_map_client(client);

    }

}
