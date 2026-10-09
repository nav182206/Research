/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6667
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f929ab0569ff31ed5a59b0b0adb7ce09df3fca39
 */

int ff_tempfile(const char *prefix, char **filename) {

    int fd=-1;

#if !HAVE_MKSTEMP

    *filename = tempnam(".", prefix);

#else

    size_t len = strlen(prefix) + 12; /* room for "/tmp/" and "XXXXXX\0" */

    *filename = av_malloc(len);

#endif

    /* -----common section-----*/

    if (*filename == NULL) {

        av_log(NULL, AV_LOG_ERROR, "ff_tempfile: Cannot allocate file name\n");

        return -1;

    }

#if !HAVE_MKSTEMP

    fd = avpriv_open(*filename, O_RDWR | O_BINARY | O_CREAT, 0444);

#else

    snprintf(*filename, len, "/tmp/%sXXXXXX", prefix);

    fd = mkstemp(*filename);

    if (fd < 0) {

        snprintf(*filename, len, "./%sXXXXXX", prefix);

        fd = mkstemp(*filename);

    }

#endif

    /* -----common section-----*/

    if (fd < 0) {

        av_log(NULL, AV_LOG_ERROR, "ff_tempfile: Cannot open temporary file %s\n", *filename);

        return -1;

    }

    return fd; /* success */

}
