/* 
 * Benchmark Sample ID : devign_9587
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ad0ebb91cd8b5fdc4a583b03645677771f420a46
 */

static int check_bd(VIOsPAPRVLANDevice *dev, vlan_bd_t bd,

                    target_ulong alignment)

{

    if ((VLAN_BD_ADDR(bd) % alignment)

        || (VLAN_BD_LEN(bd) % alignment)) {

        return -1;

    }



    if (spapr_vio_check_tces(&dev->sdev, VLAN_BD_ADDR(bd),

                             VLAN_BD_LEN(bd), SPAPR_TCE_RW) != 0) {

        return -1;

    }



    return 0;

}
