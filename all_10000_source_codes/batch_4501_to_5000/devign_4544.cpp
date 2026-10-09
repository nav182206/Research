/* 
 * Benchmark Sample ID : devign_4544
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=62f94fc94f98095173146e753a1f03d7c2cc7ba3
 */

static void icp_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);



    dc->vmsd = &vmstate_icp_server;

    dc->realize = icp_realize;


}
