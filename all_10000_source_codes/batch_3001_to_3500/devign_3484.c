/* 
 * Benchmark Sample ID : devign_3484
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=64d7e9a421fea0ac50b44541f5521de455e7cd5d
 */

void pcspk_init(PITState *pit)

{

    PCSpkState *s = &pcspk_state;



    s->pit = pit;

    register_ioport_read(0x61, 1, 1, pcspk_ioport_read, s);

    register_ioport_write(0x61, 1, 1, pcspk_ioport_write, s);

}
