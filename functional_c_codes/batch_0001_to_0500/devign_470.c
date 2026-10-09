/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_470
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static void fd_accept_incoming_migration(void *opaque)

{

    QEMUFile *f = opaque;



    qemu_set_fd_handler2(qemu_get_fd(f), NULL, NULL, NULL, NULL);

    process_incoming_migration(f);

}
