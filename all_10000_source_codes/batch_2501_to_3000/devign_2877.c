/* 
 * Benchmark Sample ID : devign_2877
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd269ebc82fbaa5fe7ce5bc7c1770ac8acecd884
 */

static void test_io_channel(bool async,

                            SocketAddressLegacy *listen_addr,

                            SocketAddressLegacy *connect_addr,

                            bool passFD)

{

    QIOChannel *src, *dst;

    QIOChannelTest *test;

    if (async) {

        test_io_channel_setup_async(listen_addr, connect_addr, &src, &dst);



        g_assert(!passFD ||

                 qio_channel_has_feature(src, QIO_CHANNEL_FEATURE_FD_PASS));

        g_assert(!passFD ||

                 qio_channel_has_feature(dst, QIO_CHANNEL_FEATURE_FD_PASS));

        g_assert(qio_channel_has_feature(src, QIO_CHANNEL_FEATURE_SHUTDOWN));

        g_assert(qio_channel_has_feature(dst, QIO_CHANNEL_FEATURE_SHUTDOWN));



        test = qio_channel_test_new();

        qio_channel_test_run_threads(test, true, src, dst);

        qio_channel_test_validate(test);



        object_unref(OBJECT(src));

        object_unref(OBJECT(dst));



        test_io_channel_setup_async(listen_addr, connect_addr, &src, &dst);



        g_assert(!passFD ||

                 qio_channel_has_feature(src, QIO_CHANNEL_FEATURE_FD_PASS));

        g_assert(!passFD ||

                 qio_channel_has_feature(dst, QIO_CHANNEL_FEATURE_FD_PASS));

        g_assert(qio_channel_has_feature(src, QIO_CHANNEL_FEATURE_SHUTDOWN));

        g_assert(qio_channel_has_feature(dst, QIO_CHANNEL_FEATURE_SHUTDOWN));



        test = qio_channel_test_new();

        qio_channel_test_run_threads(test, false, src, dst);

        qio_channel_test_validate(test);



        object_unref(OBJECT(src));

        object_unref(OBJECT(dst));

    } else {

        test_io_channel_setup_sync(listen_addr, connect_addr, &src, &dst);



        g_assert(!passFD ||

                 qio_channel_has_feature(src, QIO_CHANNEL_FEATURE_FD_PASS));

        g_assert(!passFD ||

                 qio_channel_has_feature(dst, QIO_CHANNEL_FEATURE_FD_PASS));

        g_assert(qio_channel_has_feature(src, QIO_CHANNEL_FEATURE_SHUTDOWN));

        g_assert(qio_channel_has_feature(dst, QIO_CHANNEL_FEATURE_SHUTDOWN));



        test = qio_channel_test_new();

        qio_channel_test_run_threads(test, true, src, dst);

        qio_channel_test_validate(test);



        object_unref(OBJECT(src));

        object_unref(OBJECT(dst));



        test_io_channel_setup_sync(listen_addr, connect_addr, &src, &dst);



        g_assert(!passFD ||

                 qio_channel_has_feature(src, QIO_CHANNEL_FEATURE_FD_PASS));

        g_assert(!passFD ||

                 qio_channel_has_feature(dst, QIO_CHANNEL_FEATURE_FD_PASS));

        g_assert(qio_channel_has_feature(src, QIO_CHANNEL_FEATURE_SHUTDOWN));

        g_assert(qio_channel_has_feature(dst, QIO_CHANNEL_FEATURE_SHUTDOWN));



        test = qio_channel_test_new();

        qio_channel_test_run_threads(test, false, src, dst);

        qio_channel_test_validate(test);



        object_unref(OBJECT(src));

        object_unref(OBJECT(dst));

    }

}
