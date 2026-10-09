/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6709
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d656ec5ea823bcdb59b6512cb73b3f2f97a8308f
 */

static int qio_channel_buffer_close(QIOChannel *ioc,

                                    Error **errp)

{

    QIOChannelBuffer *bioc = QIO_CHANNEL_BUFFER(ioc);



    g_free(bioc->data);


    bioc->capacity = bioc->usage = bioc->offset = 0;



    return 0;

}
