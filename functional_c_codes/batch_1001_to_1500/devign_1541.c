/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1541
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b45c03f585ea9bb1af76c73e82195418c294919d
 */

static struct omap_sysctl_s *omap_sysctl_init(struct omap_target_agent_s *ta,

                omap_clk iclk, struct omap_mpu_state_s *mpu)

{

    struct omap_sysctl_s *s = (struct omap_sysctl_s *)

            g_malloc0(sizeof(struct omap_sysctl_s));



    s->mpu = mpu;

    omap_sysctl_reset(s);



    memory_region_init_io(&s->iomem, NULL, &omap_sysctl_ops, s, "omap.sysctl",

                          omap_l4_region_size(ta, 0));

    omap_l4_attach(ta, 0, &s->iomem);



    return s;

}
