/* 
 * Benchmark Sample ID : devign_7300
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=57407ea44cc0a3d630b9b89a2be011f1955ce5c1
 */

static void stellaris_enet_cleanup(NetClientState *nc)

{

    stellaris_enet_state *s = qemu_get_nic_opaque(nc);



    s->nic = NULL;

}
