/* 
 * Benchmark Sample ID : devign_7110
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f5aa4bdc766190b95d18be27d5cdf4d80c35b33c
 */

static void test_bmdma_short_prdt(void)

{

    QPCIDevice *dev;

    QPCIBar bmdma_bar, ide_bar;

    uint8_t status;



    PrdtEntry prdt[] = {

        {

            .addr = 0,

            .size = cpu_to_le32(0x10 | PRDT_EOT),

        },

    };



    dev = get_pci_device(&bmdma_bar, &ide_bar);



    /* Normal request */

    status = send_dma_request(CMD_READ_DMA, 0, 1,

                              prdt, ARRAY_SIZE(prdt), NULL);

    g_assert_cmphex(status, ==, 0);

    assert_bit_clear(qpci_io_readb(dev, ide_bar, reg_status), DF | ERR);



    /* Abort the request before it completes */

    status = send_dma_request(CMD_READ_DMA | CMDF_ABORT, 0, 1,

                              prdt, ARRAY_SIZE(prdt), NULL);

    g_assert_cmphex(status, ==, 0);

    assert_bit_clear(qpci_io_readb(dev, ide_bar, reg_status), DF | ERR);


}
