/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6326
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=57407ea44cc0a3d630b9b89a2be011f1955ce5c1
 */

static void mipsnet_cleanup(NetClientState *nc)

{

    MIPSnetState *s = qemu_get_nic_opaque(nc);



    s->nic = NULL;

}
