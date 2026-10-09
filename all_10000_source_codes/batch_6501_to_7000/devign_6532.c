/* 
 * Benchmark Sample ID : devign_6532
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f2001a7e0555b66d6db25a3ff1801540814045bb
 */

static int tcp_chr_new_client(CharDriverState *chr, QIOChannelSocket *sioc)

{

    TCPCharDriver *s = chr->opaque;

    if (s->ioc != NULL) {

	return -1;

    }



    s->ioc = QIO_CHANNEL(sioc);

    object_ref(OBJECT(sioc));



    if (s->do_nodelay) {

        qio_channel_set_delay(s->ioc, false);

    }

    if (s->listen_tag) {

        g_source_remove(s->listen_tag);

        s->listen_tag = 0;

    }

    tcp_chr_connect(chr);



    return 0;

}
