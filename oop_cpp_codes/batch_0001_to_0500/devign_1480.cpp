/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_1480
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7797a73947d5c0e63dd5552b348cf66c384b4555
 */

static void pxa2xx_pcmcia_class_init(ObjectClass *oc, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(oc);



    dc->realize = pxa2xx_pcmcia_realize;

}
