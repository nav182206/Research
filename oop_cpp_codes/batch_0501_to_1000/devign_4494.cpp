/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4494
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0bcba41fe379e4c6834adcf1456d9099db31a5b2
 */

void machine_register_compat_props(MachineState *machine)

{

    MachineClass *mc = MACHINE_GET_CLASS(machine);

    int i;

    GlobalProperty *p;



    if (!mc->compat_props) {

        return;

    }



    for (i = 0; i < mc->compat_props->len; i++) {

        p = g_array_index(mc->compat_props, GlobalProperty *, i);

        /* Machine compat_props must never cause errors: */

        p->errp = &error_abort;

        qdev_prop_register_global(p);

    }

}
