/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4002
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=076b35b5a56bca57c4aa41044ed304fe9c45d6c5
 */

int qemu_register_machine(QEMUMachine *m)

{

    char *name = g_strconcat(m->name, TYPE_MACHINE_SUFFIX, NULL);

    TypeInfo ti = {

        .name       = name,

        .parent     = TYPE_MACHINE,

        .class_init = machine_class_init,

        .class_data = (void *)m,

    };



    type_register(&ti);

    g_free(name);



    return 0;

}
