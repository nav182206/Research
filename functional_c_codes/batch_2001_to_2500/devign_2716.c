/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2716
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7c560456707bfe53eb1728fcde759be7d9418b62
 */

fdctrl_t *sun4m_fdctrl_init (qemu_irq irq, target_phys_addr_t io_base,

                             BlockDriverState **fds)

{

    fdctrl_t *fdctrl;



    fdctrl = fdctrl_init(irq, 0, 1, io_base, fds);

    fdctrl->sun4m = 1;



    return fdctrl;

}
