/* 
 * Benchmark Sample ID : devign_9826
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=61ed73cff427206b3a959b18a4877952f566279b
 */

static ssize_t handle_aiocb_rw_linear(RawPosixAIOData *aiocb, char *buf)

{

    ssize_t offset = 0;

    ssize_t len;



    while (offset < aiocb->aio_nbytes) {

        if (aiocb->aio_type & QEMU_AIO_WRITE) {

            len = pwrite(aiocb->aio_fildes,

                         (const char *)buf + offset,

                         aiocb->aio_nbytes - offset,

                         aiocb->aio_offset + offset);

        } else {

            len = pread(aiocb->aio_fildes,

                        buf + offset,

                        aiocb->aio_nbytes - offset,

                        aiocb->aio_offset + offset);

        }

        if (len == -1 && errno == EINTR) {

            continue;










        } else if (len == -1) {

            offset = -errno;


        } else if (len == 0) {


        }

        offset += len;

    }



    return offset;

}
