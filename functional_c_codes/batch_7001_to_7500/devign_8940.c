/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8940
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ad674e53b5cce265fadafbde2c6a4f190345cd00
 */

static void conditional_interrupt(DBDMA_channel *ch)

{

    dbdma_cmd *current = &ch->current;

    uint16_t intr;

    uint16_t sel_mask, sel_value;

    uint32_t status;

    int cond;



    DBDMA_DPRINTF("conditional_interrupt\n");



    intr = le16_to_cpu(current->command) & INTR_MASK;



    switch(intr) {

    case INTR_NEVER:  /* don't interrupt */

        return;

    case INTR_ALWAYS: /* always interrupt */

        qemu_irq_raise(ch->irq);

        return;

    }



    status = be32_to_cpu(ch->regs[DBDMA_STATUS]) & DEVSTAT;



    sel_mask = (be32_to_cpu(ch->regs[DBDMA_INTR_SEL]) >> 16) & 0x0f;

    sel_value = be32_to_cpu(ch->regs[DBDMA_INTR_SEL]) & 0x0f;



    cond = (status & sel_mask) == (sel_value & sel_mask);



    switch(intr) {

    case INTR_IFSET:  /* intr if condition bit is 1 */

        if (cond)

            qemu_irq_raise(ch->irq);

        return;

    case INTR_IFCLR:  /* intr if condition bit is 0 */

        if (!cond)

            qemu_irq_raise(ch->irq);

        return;

    }

}
