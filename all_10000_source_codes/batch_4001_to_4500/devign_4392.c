/* 
 * Benchmark Sample ID : devign_4392
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=93a5364620dbfcf3cc13866d0e218fc3624c1edf
 */

static int ipmi_register_netfn(IPMIBmcSim *s, unsigned int netfn,

                               const IPMINetfn *netfnd)

{

    if ((netfn & 1) || (netfn > MAX_NETFNS) || (s->netfns[netfn / 2])) {

        return -1;

    }

    s->netfns[netfn / 2] = netfnd;

    return 0;

}
