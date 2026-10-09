/* 
 * Benchmark Sample ID : devign_1866
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e2ae6159de2482ee5e22532301eb7f2795828d07
 */

static void set_guest_connected(VirtIOSerialPort *port, int guest_connected)

{

    VirtConsole *vcon = VIRTIO_CONSOLE(port);



    if (!vcon->chr) {

        return;

    }

    qemu_chr_fe_set_open(vcon->chr, guest_connected);

}
