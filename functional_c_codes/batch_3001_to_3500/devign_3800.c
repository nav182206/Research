/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3800
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=05d00e953f4cc08273fbb5f795f4fdc307140108
 */

static int pipe_open(URLContext *h, const char *filename, int flags)

{

    int fd;



    if (flags & URL_WRONLY) {

        fd = 1;

    } else {

        fd = 0;

    }

#if defined(__MINGW32__) || defined(CONFIG_OS2) || defined(__CYGWIN__)

    setmode(fd, O_BINARY);

#endif

    h->priv_data = (void *)(size_t)fd;

    h->is_streamed = 1;

    return 0;

}
