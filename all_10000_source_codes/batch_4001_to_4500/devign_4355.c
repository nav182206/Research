/* 
 * Benchmark Sample ID : devign_4355
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void virtio_scsi_migration_state_changed(Notifier *notifier, void *data)

{

    VirtIOSCSI *s = container_of(notifier, VirtIOSCSI,

                                 migration_state_notifier);

    MigrationState *mig = data;



    if (migration_in_setup(mig)) {

        if (!s->dataplane_started) {

            return;

        }

        virtio_scsi_dataplane_stop(s);

        s->dataplane_disabled = true;

    } else if (migration_has_finished(mig) ||

               migration_has_failed(mig)) {

        if (s->dataplane_started) {

            return;

        }

        bdrv_drain_all(); /* complete in-flight non-dataplane requests */

        s->dataplane_disabled = false;

    }

}
