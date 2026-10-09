/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2742
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=32bafa8fdd098d52fbf1102d5a5e48d29398c0aa
 */

static CharDriverState *qmp_chardev_open_udp(const char *id,

                                             ChardevBackend *backend,

                                             ChardevReturn *ret,

                                             Error **errp)

{

    ChardevUdp *udp = backend->u.udp;

    ChardevCommon *common = qapi_ChardevUdp_base(udp);

    QIOChannelSocket *sioc = qio_channel_socket_new();



    if (qio_channel_socket_dgram_sync(sioc,

                                      udp->local, udp->remote,

                                      errp) < 0) {

        object_unref(OBJECT(sioc));

        return NULL;

    }

    return qemu_chr_open_udp(sioc, common, errp);

}
