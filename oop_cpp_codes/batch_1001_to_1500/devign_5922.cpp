/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5922
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

void module_call_init(module_init_type type)

{

    ModuleTypeList *l;

    ModuleEntry *e;



    l = find_type(type);



    TAILQ_FOREACH(e, l, node) {

        e->init();

    }

}
