/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1896
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

void fd_start_outgoing_migration(MigrationState *s, const char *fdname, Error **errp)

{

    int fd = monitor_get_fd(cur_mon, fdname, errp);

    if (fd == -1) {

        return;

    }

    s->file = qemu_fdopen(fd, "wb");



    migrate_fd_connect(s);

}
