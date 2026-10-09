/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_110
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=abed886ec60cf239a03515cf0b30fb11fa964c44
 */

static void device_finalize(Object *obj)

{

    NamedGPIOList *ngl, *next;



    DeviceState *dev = DEVICE(obj);

    qemu_opts_del(dev->opts);



    QLIST_FOREACH_SAFE(ngl, &dev->gpios, node, next) {

        QLIST_REMOVE(ngl, node);

        qemu_free_irqs(ngl->in, ngl->num_in);

        g_free(ngl->name);

        g_free(ngl);

        /* ngl->out irqs are owned by the other end and should not be freed

         * here

         */

    }

}
