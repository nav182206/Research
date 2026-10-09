/* 
 * Benchmark Sample ID : devign_667
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bce6261eb2d879625126485d4ddd28cacb93152e
 */

static void set_guest_connected(VirtIOSerialPort *port, int guest_connected)

{

    VirtConsole *vcon = VIRTIO_CONSOLE(port);

    DeviceState *dev = DEVICE(port);



    if (vcon->chr) {

        qemu_chr_fe_set_open(vcon->chr, guest_connected);

    }



    if (dev->id) {

        qapi_event_send_vserport_change(dev->id, guest_connected,

                                        &error_abort);

    }

}
