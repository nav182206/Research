/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_796
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=77a10d04d033484a913a5ee76eed31a9acc57bae
 */

void vfio_put_group(VFIOGroup *group)

{

    if (!QLIST_EMPTY(&group->device_list)) {

        return;

    }



    vfio_kvm_device_del_group(group);

    vfio_disconnect_container(group);

    QLIST_REMOVE(group, next);

    trace_vfio_put_group(group->fd);

    close(group->fd);

    g_free(group);



    if (QLIST_EMPTY(&vfio_group_list)) {

        qemu_unregister_reset(vfio_reset_handler, NULL);

    }

}
