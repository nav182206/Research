/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3020
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c3c3bc7ff6b25326800ef6aae3ba46f9de75d3a7
 */

int ff_win32_open(const char *filename_utf8, int oflag, int pmode)

{

    int fd;

    int num_chars;

    wchar_t *filename_w;



    /* convert UTF-8 to wide chars */

    num_chars = MultiByteToWideChar(CP_UTF8, 0, filename_utf8, -1, NULL, 0);

    if (num_chars <= 0)

        return -1;

    filename_w = av_mallocz(sizeof(wchar_t) * num_chars);

    MultiByteToWideChar(CP_UTF8, 0, filename_utf8, -1, filename_w, num_chars);



    fd = _wsopen(filename_w, oflag, SH_DENYNO, pmode);

    av_freep(&filename_w);



    /* filename maybe be in CP_ACP */

    if (fd == -1 && !(oflag & O_CREAT))

        return _sopen(filename_utf8, oflag, SH_DENYNO, pmode);



    return fd;

}
