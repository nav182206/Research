/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6807
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=74892d2468b9f0c56b915ce94848d6f7fac39740
 */

static void runstate_init(void)

{

    const RunStateTransition *p;



    memset(&runstate_valid_transitions, 0, sizeof(runstate_valid_transitions));



    for (p = &runstate_transitions_def[0]; p->from != RUN_STATE_MAX; p++) {

        runstate_valid_transitions[p->from][p->to] = true;

    }

}
