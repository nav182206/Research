/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9684
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c4843a45e3d4f3698b214275ab5e78cdb6a3d212
 */

static int vhost_user_reset_device(struct vhost_dev *dev)

{

    VhostUserMsg msg = {

        .request = VHOST_USER_RESET_OWNER,

        .flags = VHOST_USER_VERSION,

    };



    vhost_user_write(dev, &msg, NULL, 0);



    return 0;

}
