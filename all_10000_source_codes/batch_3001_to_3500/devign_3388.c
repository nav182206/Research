/* 
 * Benchmark Sample ID : devign_3388
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=333cb18ff4aaf249b2e81a376bee2b15370f4784
 */

DisplayState *init_displaystate(void)

{

    gchar *name;

    int i;



    if (!display_state) {

        display_state = g_new0(DisplayState, 1);

    }



    for (i = 0; i < nb_consoles; i++) {

        if (consoles[i]->console_type != GRAPHIC_CONSOLE &&

            consoles[i]->ds == NULL) {

            text_console_do_init(consoles[i]->chr, display_state);

        }



        /* Hook up into the qom tree here (not in new_console()), once

         * all QemuConsoles are created and the order / numbering

         * doesn't change any more */

        name = g_strdup_printf("console[%d]", i);

        object_property_add_child(container_get(object_get_root(), "/backend"),

                                  name, OBJECT(consoles[i]), &error_abort);

        g_free(name);

    }



    return display_state;

}
