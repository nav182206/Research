/* 
 * Benchmark Sample ID : devign_6982
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a89f364ae8740dfc31b321eed9ee454e996dc3c1
 */

void omap_rfbi_attach(struct omap_dss_s *s, int cs, struct rfbi_chip_s *chip)

{

    if (cs < 0 || cs > 1)

        hw_error("%s: wrong CS %i\n", __FUNCTION__, cs);

    s->rfbi.chip[cs] = chip;

}
