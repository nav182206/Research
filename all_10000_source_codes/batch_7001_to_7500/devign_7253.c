/* 
 * Benchmark Sample ID : devign_7253
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=16f4e8fa737b58b7b0461b33581e43ac06991110
 */

static DWORD WINAPI do_suspend(LPVOID opaque)

{

    GuestSuspendMode *mode = opaque;

    DWORD ret = 0;



    if (!SetSuspendState(*mode == GUEST_SUSPEND_MODE_DISK, TRUE, TRUE)) {

        slog("failed to suspend guest, %s", GetLastError());

        ret = -1;

    }

    g_free(mode);

    return ret;

}
