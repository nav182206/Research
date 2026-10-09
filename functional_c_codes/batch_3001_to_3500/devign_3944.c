/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3944
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f3a06403b82c7f036564e4caf18b52ce6885fcfb
 */

void ga_command_state_add(GACommandState *cs,

                          void (*init)(void),

                          void (*cleanup)(void))

{

    GACommandGroup *cg = g_malloc0(sizeof(GACommandGroup));

    cg->init = init;

    cg->cleanup = cleanup;

    cs->groups = g_slist_append(cs->groups, cg);

}
