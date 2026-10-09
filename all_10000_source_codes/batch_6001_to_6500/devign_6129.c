/* 
 * Benchmark Sample ID : devign_6129
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9fbf4a58c90183b30bb2c8ad971ccce7e6716a16
 */

hwaddr cpu_mips_translate_address(CPUMIPSState *env, target_ulong address, int rw)

{

    hwaddr physical;

    int prot;

    int access_type;

    int ret = 0;



    /* data access */

    access_type = ACCESS_INT;

    ret = get_physical_address(env, &physical, &prot,

                               address, rw, access_type);

    if (ret != TLBRET_MATCH) {

        raise_mmu_exception(env, address, rw, ret);

        return -1LL;

    } else {

        return physical;

    }

}
