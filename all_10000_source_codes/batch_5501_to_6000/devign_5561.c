/* 
 * Benchmark Sample ID : devign_5561
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9036de1a8ad6c565a4e5d8cd124ad8dd05e7d4d4
 */

void net_host_device_remove(Monitor *mon, int vlan_id, const char *device)

{

    VLANState *vlan;

    VLANClientState *vc;



    vlan = qemu_find_vlan(vlan_id);

    if (!vlan) {

        monitor_printf(mon, "can't find vlan %d\n", vlan_id);

        return;

    }



   for(vc = vlan->first_client; vc != NULL; vc = vc->next)

        if (!strcmp(vc->name, device))

            break;



    if (!vc) {

        monitor_printf(mon, "can't find device %s\n", device);

        return;

    }

    qemu_del_vlan_client(vc);

}
