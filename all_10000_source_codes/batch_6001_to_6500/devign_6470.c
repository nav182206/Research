/* 
 * Benchmark Sample ID : devign_6470
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a89f364ae8740dfc31b321eed9ee454e996dc3c1
 */

void omap_uwire_attach(struct omap_uwire_s *s,

                uWireSlave *slave, int chipselect)

{

    if (chipselect < 0 || chipselect > 3) {

        fprintf(stderr, "%s: Bad chipselect %i\n", __FUNCTION__, chipselect);

        exit(-1);

    }



    s->chip[chipselect] = slave;

}
