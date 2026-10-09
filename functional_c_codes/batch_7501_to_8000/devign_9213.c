/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9213
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4eae2a657d1ff5ada56eb9b4966eae0eff333b0b
 */

static void virtio_balloon_receive_stats(VirtIODevice *vdev, VirtQueue *vq)

{

    VirtIOBalloon *s = VIRTIO_BALLOON(vdev);

    VirtQueueElement *elem;

    VirtIOBalloonStat stat;

    size_t offset = 0;

    qemu_timeval tv;



    s->stats_vq_elem = elem = virtqueue_pop(vq, sizeof(VirtQueueElement));

    if (!elem) {

        goto out;

    }



    /* Initialize the stats to get rid of any stale values.  This is only

     * needed to handle the case where a guest supports fewer stats than it

     * used to (ie. it has booted into an old kernel).

     */

    reset_stats(s);



    while (iov_to_buf(elem->out_sg, elem->out_num, offset, &stat, sizeof(stat))

           == sizeof(stat)) {

        uint16_t tag = virtio_tswap16(vdev, stat.tag);

        uint64_t val = virtio_tswap64(vdev, stat.val);



        offset += sizeof(stat);

        if (tag < VIRTIO_BALLOON_S_NR)

            s->stats[tag] = val;

    }

    s->stats_vq_offset = offset;



    if (qemu_gettimeofday(&tv) < 0) {

        fprintf(stderr, "warning: %s: failed to get time of day\n", __func__);

        goto out;

    }



    s->stats_last_update = tv.tv_sec;



out:

    if (balloon_stats_enabled(s)) {

        balloon_stats_change_timer(s, s->stats_poll_interval);

    }

}
