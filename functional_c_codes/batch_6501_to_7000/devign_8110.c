/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8110
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dfe80b071b6ef6c9c0b4e36191e2fe2d16050766
 */

static void qemu_rbd_aio_event_reader(void *opaque)

{

    BDRVRBDState *s = opaque;



    ssize_t ret;



    do {

        char *p = (char *)&s->event_rcb;



        /* now read the rcb pointer that was sent from a non qemu thread */

        if ((ret = read(s->fds[RBD_FD_READ], p + s->event_reader_pos,

                        sizeof(s->event_rcb) - s->event_reader_pos)) > 0) {

            if (ret > 0) {

                s->event_reader_pos += ret;

                if (s->event_reader_pos == sizeof(s->event_rcb)) {

                    s->event_reader_pos = 0;

                    qemu_rbd_complete_aio(s->event_rcb);

                    s->qemu_aio_count--;

                }

            }

        }

    } while (ret < 0 && errno == EINTR);

}
