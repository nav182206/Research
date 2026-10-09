/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9945
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bc3e6a0d6c8ab6cd7cd4b576ed567756f1dcabd2
 */

static void pvpanic_isa_realizefn(DeviceState *dev, Error **errp)

{

    ISADevice *d = ISA_DEVICE(dev);

    PVPanicState *s = ISA_PVPANIC_DEVICE(dev);

    static bool port_configured;

    FWCfgState *fw_cfg;



    isa_register_ioport(d, &s->io, s->ioport);



    if (!port_configured) {

        fw_cfg = fw_cfg_find();

        if (fw_cfg) {

            fw_cfg_add_file(fw_cfg, "etc/pvpanic-port",

                            g_memdup(&s->ioport, sizeof(s->ioport)),

                            sizeof(s->ioport));

            port_configured = true;

        }

    }

}
