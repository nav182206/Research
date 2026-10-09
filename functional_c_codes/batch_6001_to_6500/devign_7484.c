/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7484
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9faa574f7d07109e2256c0b4b63e8711d650f2d8
 */

static void gluster_finish_aiocb(struct glfs_fd *fd, ssize_t ret, void *arg)

{

    GlusterAIOCB *acb = (GlusterAIOCB *)arg;

    BlockDriverState *bs = acb->common.bs;

    BDRVGlusterState *s = bs->opaque;

    int retval;



    acb->ret = ret;

    retval = qemu_write_full(s->fds[GLUSTER_FD_WRITE], &acb, sizeof(acb));

    if (retval != sizeof(acb)) {

        /*

         * Gluster AIO callback thread failed to notify the waiting

         * QEMU thread about IO completion.

         *

         * Complete this IO request and make the disk inaccessible for

         * subsequent reads and writes.

         */

        error_report("Gluster failed to notify QEMU about IO completion");



        qemu_mutex_lock_iothread(); /* We are in gluster thread context */

        acb->common.cb(acb->common.opaque, -EIO);

        qemu_aio_release(acb);

        close(s->fds[GLUSTER_FD_READ]);

        close(s->fds[GLUSTER_FD_WRITE]);

        qemu_aio_set_fd_handler(s->fds[GLUSTER_FD_READ], NULL, NULL, NULL);

        bs->drv = NULL; /* Make the disk inaccessible */

        qemu_mutex_unlock_iothread();

    }

}
