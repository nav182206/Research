/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9813
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ddcb73b7782cb6104479503faea04cc224f982b5
 */

static int e1000_post_load(void *opaque, int version_id)

{

    E1000State *s = opaque;

    NetClientState *nc = qemu_get_queue(s->nic);



    /* nc.link_down can't be migrated, so infer link_down according

     * to link status bit in mac_reg[STATUS] */

    nc->link_down = (s->mac_reg[STATUS] & E1000_STATUS_LU) == 0;



    return 0;

}
