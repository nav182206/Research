/* 
 * Benchmark Sample ID : devign_2234
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=206ab6e090eeddce71372041454d50d93a63017d
 */

void net_host_device_add(Monitor *mon, const char *device, const char *opts)

{

    if (!net_host_check_device(device)) {

        monitor_printf(mon, "invalid host network device %s\n", device);

        return;

    }

    if (net_client_init(device, opts ? : "") < 0) {

        monitor_printf(mon, "adding host network device %s failed\n", device);

    }

}
