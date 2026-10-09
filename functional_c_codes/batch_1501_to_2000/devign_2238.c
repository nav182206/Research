/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2238
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9cbaacf999b01b27dc3a22502705178057af66de
 */

static void gpollfds_to_select(int ret)

{

    int i;



    FD_ZERO(&rfds);

    FD_ZERO(&wfds);

    FD_ZERO(&xfds);



    if (ret <= 0) {

        return;

    }



    for (i = 0; i < gpollfds->len; i++) {

        int fd = g_array_index(gpollfds, GPollFD, i).fd;

        int revents = g_array_index(gpollfds, GPollFD, i).revents;



        if (revents & (G_IO_IN | G_IO_HUP | G_IO_ERR)) {

            FD_SET(fd, &rfds);

        }

        if (revents & (G_IO_OUT | G_IO_ERR)) {

            FD_SET(fd, &wfds);

        }

        if (revents & G_IO_PRI) {

            FD_SET(fd, &xfds);

        }

    }

}
