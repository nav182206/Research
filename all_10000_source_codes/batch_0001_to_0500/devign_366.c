/* 
 * Benchmark Sample ID : devign_366
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c963530a5b3e3e0f7304841adfe84416d82f59f6
 */

static char *assign_name(NetClientState *nc1, const char *model)

{

    NetClientState *nc;

    char buf[256];

    int id = 0;



    QTAILQ_FOREACH(nc, &net_clients, next) {

        if (nc == nc1) {

            continue;

        }

        /* For compatibility only bump id for net clients on a vlan */

        if (strcmp(nc->model, model) == 0 &&

            net_hub_id_for_client(nc, NULL) == 0) {

            id++;

        }

    }



    snprintf(buf, sizeof(buf), "%s.%d", model, id);



    return g_strdup(buf);

}
