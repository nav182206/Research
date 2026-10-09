/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3027
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=abc981bf292fb361f8a509c3611ddf2ba2c43360
 */

static void test_io_channel_ipv4_fd(void)
{
    QIOChannel *ioc;
    int fd = -1;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    g_assert_cmpint(fd, >, -1);
    ioc = qio_channel_new_fd(fd, &error_abort);
    g_assert_cmpstr(object_get_typename(OBJECT(ioc)),
                    ==,
                    TYPE_QIO_CHANNEL_SOCKET);
    object_unref(OBJECT(ioc));
