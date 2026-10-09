/* 
 * Benchmark Sample ID : devign_8410
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

void migration_fd_process_incoming(QEMUFile *f)

{

    Coroutine *co = qemu_coroutine_create(process_incoming_migration_co);



    migrate_decompress_threads_create();

    qemu_file_set_blocking(f, false);

    qemu_coroutine_enter(co, f);

}
