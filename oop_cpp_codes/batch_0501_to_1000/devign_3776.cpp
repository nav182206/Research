/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_3776
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f6351288b65130deb8102b17143f5d84f817a02a
 */

static void dp8393x_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);



    set_bit(DEVICE_CATEGORY_NETWORK, dc->categories);

    dc->realize = dp8393x_realize;

    dc->reset = dp8393x_reset;

    dc->vmsd = &vmstate_dp8393x;

    dc->props = dp8393x_properties;



}
