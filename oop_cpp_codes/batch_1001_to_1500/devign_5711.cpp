/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5711
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9e41bade85ef338afd983c109368d1bbbe931f80
 */

static void ds1338_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);

    I2CSlaveClass *k = I2C_SLAVE_CLASS(klass);



    k->init = ds1338_init;

    k->event = ds1338_event;

    k->recv = ds1338_recv;

    k->send = ds1338_send;

    dc->reset = ds1338_reset;

    dc->vmsd = &vmstate_ds1338;

}
