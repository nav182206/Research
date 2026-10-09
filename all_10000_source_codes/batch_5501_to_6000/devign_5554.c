/* 
 * Benchmark Sample ID : devign_5554
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=81174dae3f9189519cd60c7b79e91c291b021bbe
 */

static int serial_can_receive(SerialState *s)

{

    return !(s->lsr & UART_LSR_DR);

}
