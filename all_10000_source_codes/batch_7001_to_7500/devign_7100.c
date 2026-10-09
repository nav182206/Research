/* 
 * Benchmark Sample ID : devign_7100
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

static inline void out_reg(IVState *s, enum Reg reg, unsigned v)

{

    const char *name = reg2str(reg);

    QTestState *qtest = global_qtest;



    global_qtest = s->qtest;

    g_test_message("%x -> *%s\n", v, name);

    qpci_io_writel(s->dev, s->reg_base + reg, v);

    global_qtest = qtest;

}
