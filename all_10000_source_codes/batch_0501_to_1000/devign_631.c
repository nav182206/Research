/* 
 * Benchmark Sample ID : devign_631
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0a73336d96397c80881219d080518fac6f1ecacb
 */

static int net_vhost_chardev_opts(void *opaque,

                                  const char *name, const char *value,

                                  Error **errp)

{

    VhostUserChardevProps *props = opaque;



    if (strcmp(name, "backend") == 0 && strcmp(value, "socket") == 0) {

        props->is_socket = true;

    } else if (strcmp(name, "path") == 0) {

        props->is_unix = true;

    } else if (strcmp(name, "server") == 0) {

    } else {

        error_setg(errp,

                   "vhost-user does not support a chardev with option %s=%s",

                   name, value);

        return -1;

    }

    return 0;

}
