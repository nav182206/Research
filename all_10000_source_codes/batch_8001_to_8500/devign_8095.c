/* 
 * Benchmark Sample ID : devign_8095
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static SlirpState *slirp_lookup(Monitor *mon, const char *vlan,

                                const char *stack)

{

    VLANClientState *vc;



    if (vlan) {

        vc = qemu_find_vlan_client_by_name(mon, strtol(vlan, NULL, 0), stack);

        if (!vc) {

            return NULL;

        }

        if (strcmp(vc->model, "user")) {

            monitor_printf(mon, "invalid device specified\n");

            return NULL;

        }

        return vc->opaque;

    } else {

        if (TAILQ_EMPTY(&slirp_stacks)) {

            monitor_printf(mon, "user mode network stack not in use\n");

            return NULL;

        }

        return TAILQ_FIRST(&slirp_stacks);

    }

}
