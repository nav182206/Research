/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7736
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=778358d0a8f74a76488daea3c1b6fb327d8135b4
 */

FpPort *fp_port_alloc(Rocker *r, char *sw_name,

                      MACAddr *start_mac, unsigned int index,

                      NICPeers *peers)

{

    FpPort *port = g_malloc0(sizeof(FpPort));



    if (!port) {

        return NULL;

    }



    port->r = r;

    port->index = index;

    port->pport = index + 1;



    /* front-panel switch port names are 1-based */



    port->name = g_strdup_printf("%sp%d", sw_name, port->pport);



    memcpy(port->conf.macaddr.a, start_mac, sizeof(port->conf.macaddr.a));

    port->conf.macaddr.a[5] += index;

    port->conf.bootindex = -1;

    port->conf.peers = *peers;



    port->nic = qemu_new_nic(&fp_port_info, &port->conf,

                             sw_name, NULL, port);

    qemu_format_nic_info_str(qemu_get_queue(port->nic),

                             port->conf.macaddr.a);



    fp_port_reset(port);



    return port;

}
