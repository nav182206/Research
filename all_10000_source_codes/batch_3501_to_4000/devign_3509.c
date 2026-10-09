/* 
 * Benchmark Sample ID : devign_3509
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=af52fe862fba686713044efdf9158195f84535ab
 */

static void uart_send_breaks(UartState *s)

{

    int break_enabled = 1;



    qemu_chr_fe_ioctl(s->chr, CHR_IOCTL_SERIAL_SET_BREAK,

                               &break_enabled);

}
