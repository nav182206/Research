/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1242
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e95205e1f9cd2c4262b7a7b1c992a94512c86d0e
 */

static void cpu_notify_map_clients_locked(void)

{

    MapClient *client;



    while (!QLIST_EMPTY(&map_client_list)) {

        client = QLIST_FIRST(&map_client_list);

        client->callback(client->opaque);

        cpu_unregister_map_client(client);

    }

}
