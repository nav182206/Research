/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7832
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1fdc11c36971e0d4eeb2ce817f7e520b2028c2f2
 */

static void migrate_fd_put_notify(void *opaque)

{

    MigrationState *s = opaque;



    qemu_set_fd_handler2(s->fd, NULL, NULL, NULL, NULL);

    qemu_file_put_notify(s->file);

    if (qemu_file_get_error(s->file)) {

        migrate_fd_error(s);

    }

}
