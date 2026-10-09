/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8682
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static int stdio_fclose(void *opaque)

{

    QEMUFileStdio *s = opaque;

    int ret = 0;



    if (qemu_file_is_writable(s->file)) {

        int fd = fileno(s->stdio_file);

        struct stat st;



        ret = fstat(fd, &st);

        if (ret == 0 && S_ISREG(st.st_mode)) {

            /*

             * If the file handle is a regular file make sure the

             * data is flushed to disk before signaling success.

             */

            ret = fsync(fd);

            if (ret != 0) {

                ret = -errno;

                return ret;

            }

        }

    }

    if (fclose(s->stdio_file) == EOF) {

        ret = -errno;

    }

    g_free(s);

    return ret;

}
