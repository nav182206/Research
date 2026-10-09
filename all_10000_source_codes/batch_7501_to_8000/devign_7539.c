/* 
 * Benchmark Sample ID : devign_7539
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b074e6220542107afb9fad480a184775be591d2a
 */

static int console_init(SCLPEvent *event)

{

    static bool console_available;



    SCLPConsole *scon = DO_UPCAST(SCLPConsole, event, event);



    if (console_available) {

        error_report("Multiple VT220 operator consoles are not supported");

        return -1;

    }

    console_available = true;

    if (scon->chr) {

        qemu_chr_add_handlers(scon->chr, chr_can_read,

                              chr_read, NULL, scon);

    }

    scon->irq_read_vt220 = *qemu_allocate_irqs(trigger_ascii_console_data,

                                               NULL, 1);



    return 0;

}
