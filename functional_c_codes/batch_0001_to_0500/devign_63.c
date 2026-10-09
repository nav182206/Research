/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_63
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9121d02cb33c96b444a3973579f5edc119597e81
 */

static void uart_rx_reset(UartState *s)

{

    s->rx_wpos = 0;

    s->rx_count = 0;

    qemu_chr_accept_input(s->chr);



    s->r[R_SR] |= UART_SR_INTR_REMPTY;

    s->r[R_SR] &= ~UART_SR_INTR_RFUL;

}
