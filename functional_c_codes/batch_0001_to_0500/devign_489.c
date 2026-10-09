/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_489
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=46c5874e9cd752ed8ded31af03472edd8fc3efc1
 */

static sPAPRPHBState *find_phb(sPAPREnvironment *spapr, uint64_t buid)

{

    sPAPRPHBState *sphb;



    QLIST_FOREACH(sphb, &spapr->phbs, list) {

        if (sphb->buid != buid) {

            continue;

        }

        return sphb;

    }



    return NULL;

}
