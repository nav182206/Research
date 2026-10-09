/* 
 * Benchmark Sample ID : devign_1785
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3ee886c5ba77a65d6b2c2a372a091d6796ed502b
 */

static int usb_host_auto_scan(void *opaque, int bus_num, int addr, char *port,

                              int class_id, int vendor_id, int product_id,

                              const char *product_name, int speed)

{

    struct USBAutoFilter *f;

    struct USBHostDevice *s;



    /* Ignore hubs */

    if (class_id == 9)

        return 0;



    QTAILQ_FOREACH(s, &hostdevs, next) {

        f = &s->match;



        if (f->bus_num > 0 && f->bus_num != bus_num) {

            continue;

        }

        if (f->addr > 0 && f->addr != addr) {

            continue;

        }

        if (f->port != NULL && (port == NULL || strcmp(f->port, port) != 0)) {

            continue;

        }



        if (f->vendor_id > 0 && f->vendor_id != vendor_id) {

            continue;

        }



        if (f->product_id > 0 && f->product_id != product_id) {

            continue;

        }

        /* We got a match */



        /* Already attached ? */

        if (s->fd != -1) {

            return 0;

        }

        DPRINTF("husb: auto open: bus_num %d addr %d\n", bus_num, addr);



        usb_host_open(s, bus_num, addr, port, product_name, speed);

        break;

    }



    return 0;

}
