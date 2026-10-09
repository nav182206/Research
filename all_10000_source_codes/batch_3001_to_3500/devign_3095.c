/* 
 * Benchmark Sample ID : devign_3095
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cfaf6d36ae761da1033159d85d670706ffb24fb9
 */

static void exec_accept_incoming_migration(void *opaque)

{

    QEMUFile *f = opaque;

    int ret;



    ret = qemu_loadvm_state(f);

    if (ret < 0) {

        fprintf(stderr, "load of migration failed\n");

        goto err;

    }

    qemu_announce_self();

    DPRINTF("successfully loaded vm state\n");

    /* we've successfully migrated, close the fd */

    qemu_set_fd_handler2(qemu_stdio_fd(f), NULL, NULL, NULL, NULL);

    if (autostart)

        vm_start();



err:

    qemu_fclose(f);

}
