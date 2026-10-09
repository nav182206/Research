/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_403
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4cee3cf35c05c863f5acf87af915298c752eefd9
 */

char *desc_get_buf(DescInfo *info, bool read_only)

{

    PCIDevice *dev = PCI_DEVICE(info->ring->r);

    size_t size = read_only ? le16_to_cpu(info->desc.tlv_size) :

                              le16_to_cpu(info->desc.buf_size);



    if (size > info->buf_size) {

        info->buf = g_realloc(info->buf, size);

        info->buf_size = size;

    }



    if (!info->buf) {

        return NULL;

    }



    if (pci_dma_read(dev, le64_to_cpu(info->desc.buf_addr), info->buf, size)) {

        return NULL;

    }



    return info->buf;

}
