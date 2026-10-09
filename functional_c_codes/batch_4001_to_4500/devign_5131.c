/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5131
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c689b4f1bac352dcfd6ecb9a1d45337de0f1de67
 */

int64_t qmp_guest_file_open(const char *path, bool has_mode, const char *mode, Error **err)

{

    FILE *fh;

    int fd;

    int64_t ret = -1, handle;



    if (!has_mode) {

        mode = "r";

    }

    slog("guest-file-open called, filepath: %s, mode: %s", path, mode);

    fh = fopen(path, mode);

    if (!fh) {

        error_setg_errno(err, errno, "failed to open file '%s' (mode: '%s')",

                         path, mode);

        return -1;

    }



    /* set fd non-blocking to avoid common use cases (like reading from a

     * named pipe) from hanging the agent

     */

    fd = fileno(fh);

    ret = fcntl(fd, F_GETFL);

    ret = fcntl(fd, F_SETFL, ret | O_NONBLOCK);

    if (ret == -1) {

        error_setg_errno(err, errno, "failed to make file '%s' non-blocking",

                         path);

        fclose(fh);

        return -1;

    }



    handle = guest_file_handle_add(fh, err);

    if (error_is_set(err)) {

        fclose(fh);

        return -1;

    }



    slog("guest-file-open, handle: %d", handle);

    return handle;

}
