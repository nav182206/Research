/* 
 * Benchmark Sample ID : devign_9445
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b2d1fe67d09d2b6c7da647fbcea6ca0148c206d3
 */

static void usbredir_iso_packet(void *priv, uint64_t id,

    struct usb_redir_iso_packet_header *iso_packet,

    uint8_t *data, int data_len)

{

    USBRedirDevice *dev = priv;

    uint8_t ep = iso_packet->endpoint;



    DPRINTF2("iso-in status %d ep %02X len %d id %"PRIu64"\n",

             iso_packet->status, ep, data_len, id);



    if (dev->endpoint[EP2I(ep)].type != USB_ENDPOINT_XFER_ISOC) {

        ERROR("received iso packet for non iso endpoint %02X\n", ep);

        free(data);

        return;

    }



    if (dev->endpoint[EP2I(ep)].iso_started == 0) {

        DPRINTF("received iso packet for non started stream ep %02X\n", ep);

        free(data);

        return;

    }



    /* bufp_alloc also adds the packet to the ep queue */

    bufp_alloc(dev, data, data_len, iso_packet->status, ep);

}
