/* 
 * Benchmark Sample ID : devign_8380
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=680e60b6ba5a26332d684a60a6d9f39c0a999941
 */

e1000e_set_pbaclr(E1000ECore *core, int index, uint32_t val)

{

    int i;



    core->mac[PBACLR] = val & E1000_PBACLR_VALID_MASK;



    if (msix_enabled(core->owner)) {

        return;

    }



    for (i = 0; i < E1000E_MSIX_VEC_NUM; i++) {

        if (core->mac[PBACLR] & BIT(i)) {

            msix_clr_pending(core->owner, i);

        }

    }

}
