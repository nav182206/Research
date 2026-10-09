/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2910
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

static inline void write_mem(IVState *s, uint64_t off,

                             const void *buf, size_t len)

{

    QTestState *qtest = global_qtest;



    global_qtest = s->qtest;

    qpci_memwrite(s->dev, s->mem_base + off, buf, len);

    global_qtest = qtest;

}
