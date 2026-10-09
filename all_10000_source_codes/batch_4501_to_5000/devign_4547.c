/* 
 * Benchmark Sample ID : devign_4547
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

static void test_tco1_control_bits(void)

{

    TestData d;

    uint16_t val;



    d.args = NULL;

    d.noreboot = true;

    test_init(&d);



    val = TCO_LOCK;

    qpci_io_writew(d.dev, d.tco_io_base + TCO1_CNT, val);

    val &= ~TCO_LOCK;

    qpci_io_writew(d.dev, d.tco_io_base + TCO1_CNT, val);

    g_assert_cmpint(qpci_io_readw(d.dev, d.tco_io_base + TCO1_CNT), ==,

                    TCO_LOCK);

    qtest_end();

}
