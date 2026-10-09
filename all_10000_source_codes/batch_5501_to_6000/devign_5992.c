/* 
 * Benchmark Sample ID : devign_5992
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0c6f807f4a98e7e258765dcf22619a582995fce0
 */

int usb_desc_msos(const USBDesc *desc,  USBPacket *p,

                  int index, uint8_t *dest, size_t len)

{

    void *buf = g_malloc0(4096);

    int length = 0;



    switch (index) {

    case 0x0004:

        length = usb_desc_msos_compat(desc, buf);

        break;

    case 0x0005:

        length = usb_desc_msos_prop(desc, buf);

        break;

    }



    if (length > len) {

        length = len;

    }

    memcpy(dest, buf, length);

    free(buf);



    p->actual_length = length;

    return 0;

}
