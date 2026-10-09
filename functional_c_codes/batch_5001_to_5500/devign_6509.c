/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6509
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a8fb542705ac7e0dcf00908bc47bf49cdd058abe
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



    if (s->do_telnetopt) {

        tcp_chr_telnet_init(chr);

    } else {

        tcp_chr_connect(chr);

    }



    return 0;

}
