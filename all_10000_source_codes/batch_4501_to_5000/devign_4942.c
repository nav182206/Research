/* 
 * Benchmark Sample ID : devign_4942
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=af7e9e74c6a62a5bcd911726a9e88d28b61490e0
 */

static void openpic_save_IRQ_queue(QEMUFile* f, IRQ_queue_t *q)

{

    unsigned int i;



    for (i = 0; i < BF_WIDTH(MAX_IRQ); i++)

        qemu_put_be32s(f, &q->queue[i]);



    qemu_put_sbe32s(f, &q->next);

    qemu_put_sbe32s(f, &q->priority);

}
