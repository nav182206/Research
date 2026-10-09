/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8597
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=983bff3530782d51c46c8d7c0e17e2a9dfe5fb77
 */

static void usb_mtp_handle_reset(USBDevice *dev)

{

    MTPState *s = USB_MTP(dev);



    trace_usb_mtp_reset(s->dev.addr);



#ifdef __linux__

    usb_mtp_inotify_cleanup(s);

#endif

    usb_mtp_object_free(s, QTAILQ_FIRST(&s->objects));

    s->session = 0;

    usb_mtp_data_free(s->data_in);

    s->data_in = NULL;

    usb_mtp_data_free(s->data_out);

    s->data_out = NULL;

    g_free(s->result);

    s->result = NULL;

}
