/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3335
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=eefa3d8ef649f9055611361e2201cca49f8c3433
 */

qio_channel_websock_source_check(GSource *source)

{

    QIOChannelWebsockSource *wsource = (QIOChannelWebsockSource *)source;

    GIOCondition cond = 0;



    if (wsource->wioc->rawinput.offset) {

        cond |= G_IO_IN;

    }

    if (wsource->wioc->rawoutput.offset < QIO_CHANNEL_WEBSOCK_MAX_BUFFER) {

        cond |= G_IO_OUT;

    }



    return cond & wsource->condition;

}
