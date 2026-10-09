/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2760
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=04097f7c5957273c578f72b9bd603ba6b1d69e33
 */

static int vhost_client_migration_log(CPUPhysMemoryClient *client,

                                      int enable)

{

    struct vhost_dev *dev = container_of(client, struct vhost_dev, client);

    int r;

    if (!!enable == dev->log_enabled) {

        return 0;

    }

    if (!dev->started) {

        dev->log_enabled = enable;

        return 0;

    }

    if (!enable) {

        r = vhost_dev_set_log(dev, false);

        if (r < 0) {

            return r;

        }

        if (dev->log) {

            g_free(dev->log);

        }

        dev->log = NULL;

        dev->log_size = 0;

    } else {

        vhost_dev_log_resize(dev, vhost_get_log_size(dev));

        r = vhost_dev_set_log(dev, true);

        if (r < 0) {

            return r;

        }

    }

    dev->log_enabled = enable;

    return 0;

}
