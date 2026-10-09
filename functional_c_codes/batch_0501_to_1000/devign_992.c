/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_992
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=57407ea44cc0a3d630b9b89a2be011f1955ce5c1
 */

static void aw_emac_cleanup(NetClientState *nc)

{

    AwEmacState *s = qemu_get_nic_opaque(nc);



    s->nic = NULL;

}
