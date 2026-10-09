/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9726
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a1e985833cde3208b0f57c4c7e640b60fbc6c54d
 */

static const ppc_def_t *ppc_find_by_pvr (uint32_t pvr)

{

    int i;



    for (i = 0; i < ARRAY_SIZE(ppc_defs); i++) {

        /* If we have an exact match, we're done */

        if (pvr == ppc_defs[i].pvr) {

            return &ppc_defs[i];

        }

    }



    return NULL;

}
