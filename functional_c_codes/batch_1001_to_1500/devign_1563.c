/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1563
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9bd7854e1e5d6f4cfe4558090bbd9493c12bf846
 */

static void win_chr_readfile(CharDriverState *chr)

{

    WinCharState *s = chr->opaque;

    int ret, err;

    uint8_t buf[1024];

    DWORD size;



    ZeroMemory(&s->orecv, sizeof(s->orecv));

    s->orecv.hEvent = s->hrecv;

    ret = ReadFile(s->hcom, buf, s->len, &size, &s->orecv);

    if (!ret) {

        err = GetLastError();

        if (err == ERROR_IO_PENDING) {

            ret = GetOverlappedResult(s->hcom, &s->orecv, &size, TRUE);

        }

    }



    if (size > 0) {

        qemu_chr_read(chr, buf, size);

    }

}
