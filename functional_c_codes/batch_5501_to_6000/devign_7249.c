/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7249
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=403e633126b7a781ecd48a29e3355770d46bbf1a
 */

void qemu_thread_create(QemuThread *thread,

                       void *(*start_routine)(void *),

                       void *arg, int mode)

{

    HANDLE hThread;



    assert(mode == QEMU_THREAD_DETACHED);



    struct QemuThreadData *data;

    qemu_thread_init();

    data = g_malloc(sizeof *data);

    data->thread = thread;

    data->start_routine = start_routine;

    data->arg = arg;



    hThread = (HANDLE) _beginthreadex(NULL, 0, win32_start_routine,

                                      data, 0, NULL);

    if (!hThread) {

        error_exit(GetLastError(), __func__);

    }

    CloseHandle(hThread);

}
