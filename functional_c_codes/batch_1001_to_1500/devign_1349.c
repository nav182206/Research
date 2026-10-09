/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1349
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b9ec9bd468b2c5b218d16642e8f8ea4df60418bb
 */

static int vhost_user_cleanup(struct vhost_dev *dev)

{

    struct vhost_user *u;



    assert(dev->vhost_ops->backend_type == VHOST_BACKEND_TYPE_USER);



    u = dev->opaque;

    if (u->slave_fd >= 0) {


        close(u->slave_fd);

        u->slave_fd = -1;

    }

    g_free(u);

    dev->opaque = 0;



    return 0;

}
