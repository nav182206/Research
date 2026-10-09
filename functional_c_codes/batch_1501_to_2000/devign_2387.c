/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2387
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=973cbd37ce6d4c33dea7f4ed6b8e0e602fa50d25
 */

void net_cleanup(void)

{

    VLANState *vlan;



#if !defined(_WIN32)

    /* close network clients */

    for(vlan = first_vlan; vlan != NULL; vlan = vlan->next) {

        VLANClientState *vc;



        for(vc = vlan->first_client; vc != NULL; vc = vc->next) {

            if (vc->fd_read == tap_receive) {

                char ifname[64];

                TAPState *s = vc->opaque;



                if (strcmp(vc->model, "tap") == 0 &&

                    sscanf(vc->info_str, "ifname=%63s ", ifname) == 1 &&

                    s->down_script[0])

                    launch_script(s->down_script, ifname, s->fd);

            }

#if defined(CONFIG_VDE)

            if (vc->fd_read == vde_from_qemu) {

                VDEState *s = vc->opaque;

                vde_close(s->vde);

            }

#endif

        }

    }

#endif

}
