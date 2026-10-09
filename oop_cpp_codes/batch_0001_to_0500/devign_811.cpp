/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_811
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

void do_info_usernet(Monitor *mon)

{

    SlirpState *s;



    TAILQ_FOREACH(s, &slirp_stacks, entry) {

        monitor_printf(mon, "VLAN %d (%s):\n", s->vc->vlan->id, s->vc->name);

        slirp_connection_info(s->slirp, mon);

    }

}
