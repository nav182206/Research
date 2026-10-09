/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7589
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=640601c7cb1b6b41d3e1a435b986266c2b71e9bc
 */

vu_queue_notify(VuDev *dev, VuVirtq *vq)

{

    if (unlikely(dev->broken)) {

        return;

    }



    if (!vring_notify(dev, vq)) {

        DPRINT("skipped notify...\n");

        return;

    }



    if (eventfd_write(vq->call_fd, 1) < 0) {

        vu_panic(dev, "Error writing eventfd: %s", strerror(errno));

    }

}
