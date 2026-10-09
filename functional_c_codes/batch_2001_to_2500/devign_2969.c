/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2969
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=81174dae3f9189519cd60c7b79e91c291b021bbe
 */

static void serial_receive1(void *opaque, const uint8_t *buf, int size)

{

    SerialState *s = opaque;

    serial_receive_byte(s, buf[0]);

}
