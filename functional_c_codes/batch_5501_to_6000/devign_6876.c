/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6876
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1bc04a8880374407c4b12d82ceb8752e12ff5336
 */

static bool pmsav7_rgnr_vmstate_validate(void *opaque, int version_id)

{

    ARMCPU *cpu = opaque;



    return cpu->env.pmsav7.rnr < cpu->pmsav7_dregion;

}
