/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4545
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4eae2a657d1ff5ada56eb9b4966eae0eff333b0b
 */

static void balloon_stats_poll_cb(void *opaque)

{

    VirtIOBalloon *s = opaque;

    VirtIODevice *vdev = VIRTIO_DEVICE(s);



    if (!balloon_stats_supported(s)) {

        /* re-schedule */

        balloon_stats_change_timer(s, s->stats_poll_interval);

        return;

    }



    virtqueue_push(s->svq, s->stats_vq_elem, s->stats_vq_offset);

    virtio_notify(vdev, s->svq);

    g_free(s->stats_vq_elem);

    s->stats_vq_elem = NULL;

}
