/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1550
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1a6245a5b0b4e8d822c739b403fc67c8a7bc8d12
 */

static ssize_t drop_sync(int fd, size_t size)

{

    ssize_t ret, dropped = size;

    uint8_t *buffer = g_malloc(MIN(65536, size));



    while (size > 0) {

        ret = read_sync(fd, buffer, MIN(65536, size));

        if (ret < 0) {

            g_free(buffer);

            return ret;

        }



        assert(ret <= size);

        size -= ret;

    }



    g_free(buffer);

    return dropped;

}
