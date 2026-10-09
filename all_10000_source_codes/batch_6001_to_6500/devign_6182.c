/* 
 * Benchmark Sample ID : devign_6182
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6687b79d636cd60ed9adb1177d0d946b58fa7717
 */

static void print_net_client(Monitor *mon, VLANClientState *vc)

{

    monitor_printf(mon, "%s: type=%s,%s\n", vc->name,

                   net_client_types[vc->info->type].type, vc->info_str);

}
