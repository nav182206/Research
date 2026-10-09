/* 
 * Benchmark Sample ID : devign_5282
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1e7398a140f7a6bd9f5a438e7ad0f1ef50990e25
 */

static int vhost_user_start(VhostUserState *s)

{

    VhostNetOptions options;



    if (vhost_user_running(s)) {

        return 0;

    }



    options.backend_type = VHOST_BACKEND_TYPE_USER;

    options.net_backend = &s->nc;

    options.opaque = s->chr;

    options.force = true;



    s->vhost_net = vhost_net_init(&options);



    return vhost_user_running(s) ? 0 : -1;

}
