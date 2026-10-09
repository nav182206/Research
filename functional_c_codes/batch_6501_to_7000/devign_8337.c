/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8337
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a89f364ae8740dfc31b321eed9ee454e996dc3c1
 */

static void palmte_onoff_gpios(void *opaque, int line, int level)

{

    switch (line) {

    case 0:

        printf("%s: current to MMC/SD card %sabled.\n",

                        __FUNCTION__, level ? "dis" : "en");

        break;

    case 1:

        printf("%s: internal speaker amplifier %s.\n",

                        __FUNCTION__, level ? "down" : "on");

        break;



    /* These LCD & Audio output signals have not been identified yet.  */

    case 2:

    case 3:

    case 4:

        printf("%s: LCD GPIO%i %s.\n",

                        __FUNCTION__, line - 1, level ? "high" : "low");

        break;

    case 5:

    case 6:

        printf("%s: Audio GPIO%i %s.\n",

                        __FUNCTION__, line - 4, level ? "high" : "low");

        break;

    }

}
