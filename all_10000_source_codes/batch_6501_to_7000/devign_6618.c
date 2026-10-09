/* 
 * Benchmark Sample ID : devign_6618
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e30f328c7429d4e891ce6da26af95c607f392739
 */

static size_t write_to_port(VirtIOSerialPort *port,

                            const uint8_t *buf, size_t size)

{

    VirtQueueElement elem;

    VirtQueue *vq;

    size_t offset = 0;

    size_t len = 0;



    vq = port->ivq;

    if (!virtio_queue_ready(vq)) {

        return 0;

    }

    if (!size) {

        return 0;

    }



    while (offset < size) {

        int i;



        if (!virtqueue_pop(vq, &elem)) {

            break;

        }



        for (i = 0; offset < size && i < elem.in_num; i++) {

            len = MIN(elem.in_sg[i].iov_len, size - offset);



            memcpy(elem.in_sg[i].iov_base, buf + offset, len);

            offset += len;

        }

        virtqueue_push(vq, &elem, len);

    }



    virtio_notify(&port->vser->vdev, vq);

    return offset;

}
