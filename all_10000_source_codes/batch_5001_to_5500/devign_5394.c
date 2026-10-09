/* 
 * Benchmark Sample ID : devign_5394
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=31ce5e0c49821d92fb30cce2f3055ef33613b287
 */

static void do_inject_mce(Monitor *mon, const QDict *qdict)

{

    CPUState *cenv;

    int cpu_index = qdict_get_int(qdict, "cpu_index");

    int bank = qdict_get_int(qdict, "bank");

    uint64_t status = qdict_get_int(qdict, "status");

    uint64_t mcg_status = qdict_get_int(qdict, "mcg_status");

    uint64_t addr = qdict_get_int(qdict, "addr");

    uint64_t misc = qdict_get_int(qdict, "misc");



    for (cenv = first_cpu; cenv != NULL; cenv = cenv->next_cpu)

        if (cenv->cpu_index == cpu_index && cenv->mcg_cap) {

            cpu_inject_x86_mce(cenv, bank, status, mcg_status, addr, misc);

            break;

        }

}
