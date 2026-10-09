/* 
 * Benchmark Sample ID : devign_3640
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e61da14d60ba1cceacad8396adcb9662c7f690af
 */

static void control_out(VirtIODevice *vdev, VirtQueue *vq)

{

    VirtQueueElement elem;

    VirtIOSerial *vser;



    vser = DO_UPCAST(VirtIOSerial, vdev, vdev);



    while (virtqueue_pop(vq, &elem)) {

        handle_control_message(vser, elem.out_sg[0].iov_base);

        virtqueue_push(vq, &elem, elem.out_sg[0].iov_len);

    }

    virtio_notify(vdev, vq);

}
