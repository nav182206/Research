/* 
 * Benchmark Sample ID : devign_4099
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8be7e7e4c72c048b90e3482557954a24bba43ba7
 */

static QemuOpts *opts_parse(QemuOptsList *list, const char *params,

                            int permit_abbrev, bool defaults)

{

    const char *firstname;

    char value[1024], *id = NULL;

    const char *p;

    QemuOpts *opts;



    assert(!permit_abbrev || list->implied_opt_name);

    firstname = permit_abbrev ? list->implied_opt_name : NULL;



    if (strncmp(params, "id=", 3) == 0) {

        get_opt_value(value, sizeof(value), params+3);

        id = value;

    } else if ((p = strstr(params, ",id=")) != NULL) {

        get_opt_value(value, sizeof(value), p+4);

        id = value;

    }

    if (defaults) {

        if (!id && !QTAILQ_EMPTY(&list->head)) {

            opts = qemu_opts_find(list, NULL);

        } else {

            opts = qemu_opts_create(list, id, 0);

        }

    } else {

        opts = qemu_opts_create(list, id, 1);

    }

    if (opts == NULL)

        return NULL;



    if (opts_do_parse(opts, params, firstname, defaults) != 0) {

        qemu_opts_del(opts);

        return NULL;

    }



    return opts;

}
