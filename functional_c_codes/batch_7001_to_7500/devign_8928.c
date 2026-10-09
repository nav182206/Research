/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8928
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e122636562218b3d442cd2cd18fbc188dd9ce709
 */

static void socket_start_outgoing_migration(MigrationState *s,

                                            SocketAddress *saddr,

                                            Error **errp)

{

    QIOChannelSocket *sioc = qio_channel_socket_new();

    qio_channel_socket_connect_async(sioc,

                                     saddr,

                                     socket_outgoing_migration,

                                     s,

                                     NULL);

    qapi_free_SocketAddress(saddr);

}
