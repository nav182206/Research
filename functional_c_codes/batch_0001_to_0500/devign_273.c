/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_273
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a5b39cd3f647eaaaef5b648beda5cb2f387418c0
 */

static VFIOINTp *vfio_init_intp(VFIODevice *vbasedev,

                                struct vfio_irq_info info)

{

    int ret;

    VFIOPlatformDevice *vdev =

        container_of(vbasedev, VFIOPlatformDevice, vbasedev);

    SysBusDevice *sbdev = SYS_BUS_DEVICE(vdev);

    VFIOINTp *intp;



    intp = g_malloc0(sizeof(*intp));

    intp->vdev = vdev;

    intp->pin = info.index;

    intp->flags = info.flags;

    intp->state = VFIO_IRQ_INACTIVE;

    intp->kvm_accel = false;



    sysbus_init_irq(sbdev, &intp->qemuirq);



    /* Get an eventfd for trigger */

    intp->interrupt = g_malloc0(sizeof(EventNotifier));

    ret = event_notifier_init(intp->interrupt, 0);

    if (ret) {

        g_free(intp->interrupt);

        g_free(intp);

        error_report("vfio: Error: trigger event_notifier_init failed ");

        return NULL;

    }

    /* Get an eventfd for resample/unmask */

    intp->unmask = g_malloc0(sizeof(EventNotifier));

    ret = event_notifier_init(intp->unmask, 0);

    if (ret) {

        g_free(intp->interrupt);

        g_free(intp->unmask);

        g_free(intp);

        error_report("vfio: Error: resamplefd event_notifier_init failed");

        return NULL;

    }



    QLIST_INSERT_HEAD(&vdev->intp_list, intp, next);

    return intp;

}
