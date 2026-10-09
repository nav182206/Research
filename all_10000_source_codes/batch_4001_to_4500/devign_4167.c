/* 
 * Benchmark Sample ID : devign_4167
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=71e605f80313a632cc6714cde7bd240042dbdd95
 */

static int fifo_put(SerialState *s, int fifo, uint8_t chr)

{

    SerialFIFO *f = (fifo) ? &s->recv_fifo : &s->xmit_fifo;



    f->data[f->head++] = chr;



    if (f->head == UART_FIFO_LENGTH)

        f->head = 0;

    f->count++;



    return 1;

}
