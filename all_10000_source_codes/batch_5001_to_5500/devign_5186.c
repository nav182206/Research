/* 
 * Benchmark Sample ID : devign_5186
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3791f83ca999edc2d11eb2006ccc1091cd712c15
 */

int net_init_dump(const NetClientOptions *opts, const char *name,

                  NetClientState *peer, Error **errp)

{

    /* FIXME error_setg(errp, ...) on failure */

    int len;

    const char *file;

    char def_file[128];

    const NetdevDumpOptions *dump;



    assert(opts->kind == NET_CLIENT_OPTIONS_KIND_DUMP);

    dump = opts->dump;



    assert(peer);



    if (dump->has_file) {

        file = dump->file;

    } else {

        int id;

        int ret;



        ret = net_hub_id_for_client(peer, &id);

        assert(ret == 0); /* peer must be on a hub */



        snprintf(def_file, sizeof(def_file), "qemu-vlan%d.pcap", id);

        file = def_file;

    }



    if (dump->has_len) {

        if (dump->len > INT_MAX) {

            error_report("invalid length: %"PRIu64, dump->len);

            return -1;

        }

        len = dump->len;

    } else {

        len = 65536;

    }



    return net_dump_init(peer, "dump", name, file, len);

}
