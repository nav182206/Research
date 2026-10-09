/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9568
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void virtio_blk_migration_state_changed(Notifier *notifier, void *data)

{

    VirtIOBlock *s = container_of(notifier, VirtIOBlock,

                                  migration_state_notifier);

    MigrationState *mig = data;

    Error *err = NULL;



    if (migration_in_setup(mig)) {

        if (!s->dataplane) {

            return;

        }

        virtio_blk_data_plane_destroy(s->dataplane);

        s->dataplane = NULL;

    } else if (migration_has_finished(mig) ||

               migration_has_failed(mig)) {

        if (s->dataplane) {

            return;

        }

        bdrv_drain_all(); /* complete in-flight non-dataplane requests */

        virtio_blk_data_plane_create(VIRTIO_DEVICE(s), &s->conf,

                                     &s->dataplane, &err);

        if (err != NULL) {

            error_report("%s", error_get_pretty(err));

            error_free(err);

        }

    }

}
