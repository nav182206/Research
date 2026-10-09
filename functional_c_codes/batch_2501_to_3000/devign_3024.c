/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3024
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=81174dae3f9189519cd60c7b79e91c291b021bbe
 */

SerialState *serial_mm_init (target_phys_addr_t base, int it_shift,

                             qemu_irq irq, int baudbase,

                             CharDriverState *chr, int ioregister)

{

    SerialState *s;

    int s_io_memory;



    s = qemu_mallocz(sizeof(SerialState));

    if (!s)

        return NULL;

    s->irq = irq;

    s->base = base;

    s->it_shift = it_shift;

    s->baudbase= baudbase;



    s->tx_timer = qemu_new_timer(vm_clock, serial_tx_done, s);

    if (!s->tx_timer)

        return NULL;



    qemu_register_reset(serial_reset, s);

    serial_reset(s);



    register_savevm("serial", base, 2, serial_save, serial_load, s);



    if (ioregister) {

        s_io_memory = cpu_register_io_memory(0, serial_mm_read,

                                             serial_mm_write, s);

        cpu_register_physical_memory(base, 8 << it_shift, s_io_memory);

    }

    s->chr = chr;

    qemu_chr_add_handlers(chr, serial_can_receive1, serial_receive1,

                          serial_event, s);

    return s;

}
