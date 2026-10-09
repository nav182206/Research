/* 
 * Benchmark Sample ID : devign_6740
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a980f7f2c2f4d7e9a1eba4f804cd66dbd458b6d4
 */

static void pci_basic_config(void)

{

    QVirtIO9P *v9p;

    void *addr;

    size_t tag_len;

    char *tag;

    int i;



    qvirtio_9p_start();

    v9p = qvirtio_9p_pci_init();



    addr = ((QVirtioPCIDevice *) v9p->dev)->addr + VIRTIO_PCI_CONFIG_OFF(false);

    tag_len = qvirtio_config_readw(v9p->dev,

                                   (uint64_t)(uintptr_t)addr);

    g_assert_cmpint(tag_len, ==, strlen(mount_tag));

    addr += sizeof(uint16_t);



    tag = g_malloc(tag_len);

    for (i = 0; i < tag_len; i++) {

        tag[i] = qvirtio_config_readb(v9p->dev, (uint64_t)(uintptr_t)addr + i);

    }

    g_assert_cmpmem(tag, tag_len, mount_tag, tag_len);

    g_free(tag);



    qvirtio_9p_pci_free(v9p);

    qvirtio_9p_stop();

}
