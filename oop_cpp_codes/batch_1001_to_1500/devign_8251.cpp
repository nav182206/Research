/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_8251
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9083da1d4c9dfff30d411f8c73ea494e9d78de1b
 */

RxFilterInfoList *qmp_query_rx_filter(bool has_name, const char *name,

                                      Error **errp)

{

    NetClientState *nc;

    RxFilterInfoList *filter_list = NULL, *last_entry = NULL;



    QTAILQ_FOREACH(nc, &net_clients, next) {

        RxFilterInfoList *entry;

        RxFilterInfo *info;



        if (has_name && strcmp(nc->name, name) != 0) {

            continue;

        }



        /* only query rx-filter information of NIC */

        if (nc->info->type != NET_CLIENT_OPTIONS_KIND_NIC) {

            if (has_name) {

                error_setg(errp, "net client(%s) isn't a NIC", name);

                break;

            }

            continue;

        }



        if (nc->info->query_rx_filter) {

            info = nc->info->query_rx_filter(nc);

            entry = g_malloc0(sizeof(*entry));

            entry->value = info;



            if (!filter_list) {

                filter_list = entry;

            } else {

                last_entry->next = entry;

            }

            last_entry = entry;

        } else if (has_name) {

            error_setg(errp, "net client(%s) doesn't support"

                       " rx-filter querying", name);

            break;

        }



        if (has_name) {

            break;

        }

    }



    if (filter_list == NULL && !error_is_set(errp) && has_name) {

        error_setg(errp, "invalid net client name: %s", name);

    }



    return filter_list;

}
