/* 
 * Benchmark Sample ID : devign_4076
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=920639cab0fe28d003c90b53bd8b66e8fb333bdd
 */

GuestFileWrite *qmp_guest_file_write(int64_t handle, const char *buf_b64,

                                     bool has_count, int64_t count,

                                     Error **errp)

{

    GuestFileWrite *write_data = NULL;

    guchar *buf;

    gsize buf_len;

    bool is_ok;

    DWORD write_count;

    GuestFileHandle *gfh = guest_file_handle_find(handle, errp);

    HANDLE fh;



    if (!gfh) {

        return NULL;

    }

    fh = gfh->fh;

    buf = g_base64_decode(buf_b64, &buf_len);



    if (!has_count) {

        count = buf_len;

    } else if (count < 0 || count > buf_len) {

        error_setg(errp, "value '%" PRId64

                   "' is invalid for argument count", count);

        goto done;

    }



    is_ok = WriteFile(fh, buf, count, &write_count, NULL);

    if (!is_ok) {

        error_setg_win32(errp, GetLastError(), "failed to write to file");

        slog("guest-file-write-failed, handle: %" PRId64, handle);

    } else {

        write_data = g_new0(GuestFileWrite, 1);

        write_data->count = (size_t) write_count;

    }



done:

    g_free(buf);

    return write_data;

}
