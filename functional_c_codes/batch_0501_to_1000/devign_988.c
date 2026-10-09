/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_988
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=db39fcf1f690b02d612e2bfc00980700887abe03
 */

static CharDriverState *qemu_chr_open_udp_fd(int fd)

{

    CharDriverState *chr = NULL;

    NetCharDriver *s = NULL;



    chr = g_malloc0(sizeof(CharDriverState));

    s = g_malloc0(sizeof(NetCharDriver));



    s->fd = fd;

    s->chan = io_channel_from_socket(s->fd);

    s->bufcnt = 0;

    s->bufptr = 0;

    chr->opaque = s;

    chr->chr_write = udp_chr_write;

    chr->chr_update_read_handler = udp_chr_update_read_handler;

    chr->chr_close = udp_chr_close;

    /* be isn't opened until we get a connection */

    chr->explicit_be_open = true;

    return chr;

}
