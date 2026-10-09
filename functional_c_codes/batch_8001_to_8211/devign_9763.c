/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9763
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5e6b701aba8689a336297dda047bf760ffc05291
 */

static int con_init(struct XenDevice *xendev)

{

    struct XenConsole *con = container_of(xendev, struct XenConsole, xendev);

    char *type, *dom;



    /* setup */

    dom = xs_get_domain_path(xenstore, con->xendev.dom);

    snprintf(con->console, sizeof(con->console), "%s/console", dom);

    free(dom);



    type = xenstore_read_str(con->console, "type");

    if (!type || strcmp(type, "ioemu") != 0) {

	xen_be_printf(xendev, 1, "not for me (type=%s)\n", type);

	return -1;

    }



    if (!serial_hds[con->xendev.dev])

	xen_be_printf(xendev, 1, "WARNING: serial line %d not configured\n",

                      con->xendev.dev);

    else

        con->chr = serial_hds[con->xendev.dev];



    return 0;

}
