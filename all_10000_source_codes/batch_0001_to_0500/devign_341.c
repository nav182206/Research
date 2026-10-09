/* 
 * Benchmark Sample ID : devign_341
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c4843a45e3d4f3698b214275ab5e78cdb6a3d212
 */

static int vhost_set_vring_file(struct vhost_dev *dev,

                                VhostUserRequest request,

                                struct vhost_vring_file *file)

{

    int fds[VHOST_MEMORY_MAX_NREGIONS];

    size_t fd_num = 0;

    VhostUserMsg msg = {

        .request = request,

        .flags = VHOST_USER_VERSION,

        .payload.u64 = file->index & VHOST_USER_VRING_IDX_MASK,

        .size = sizeof(msg.payload.u64),

    };



    if (ioeventfd_enabled() && file->fd > 0) {

        fds[fd_num++] = file->fd;

    } else {

        msg.payload.u64 |= VHOST_USER_VRING_NOFD_MASK;

    }



    vhost_user_write(dev, &msg, fds, fd_num);



    return 0;

}
