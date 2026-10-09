/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5794
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fea7d5966a54a5e5400cd38897a95ea576b5af4d
 */

static void pvpanic_fw_cfg(ISADevice *dev, FWCfgState *fw_cfg)

{

    PVPanicState *s = ISA_PVPANIC_DEVICE(dev);



    fw_cfg_add_file(fw_cfg, "etc/pvpanic-port",

                    g_memdup(&s->ioport, sizeof(s->ioport)),

                    sizeof(s->ioport));

}
