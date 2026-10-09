/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4306
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7f4a930e64b9e69cd340395a7e4f0494aef4fcdd
 */

static int vhost_user_set_u64(struct vhost_dev *dev, int request, uint64_t u64)

{

    VhostUserMsg msg = {

        .request = request,

        .flags = VHOST_USER_VERSION,

        .u64 = u64,

        .size = sizeof(m.u64),

    };



    vhost_user_write(dev, &msg, NULL, 0);



    return 0;

}
