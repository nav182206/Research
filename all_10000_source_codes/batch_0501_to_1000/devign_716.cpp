/* 
 * Benchmark Sample ID : devign_716
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=94ad93bd976841c26af75322301f5aad925114d6
 */

static void spapr_cpu_core_unrealizefn(DeviceState *dev, Error **errp)

{

    sPAPRCPUCore *sc = SPAPR_CPU_CORE(OBJECT(dev));

    sPAPRCPUCoreClass *scc = SPAPR_CPU_CORE_GET_CLASS(OBJECT(dev));

    size_t size = object_type_get_instance_size(scc->cpu_type);

    CPUCore *cc = CPU_CORE(dev);

    int i;



    for (i = 0; i < cc->nr_threads; i++) {

        void *obj = sc->threads + i * size;

        DeviceState *dev = DEVICE(obj);

        CPUState *cs = CPU(dev);

        PowerPCCPU *cpu = POWERPC_CPU(cs);



        spapr_cpu_destroy(cpu);

        object_unparent(cpu->intc);

        cpu_remove_sync(cs);

        object_unparent(obj);

    }

    g_free(sc->threads);

}
