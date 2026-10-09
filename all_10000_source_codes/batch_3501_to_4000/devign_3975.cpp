/* 
 * Benchmark Sample ID : devign_3975
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6f2ea22a05b429ba83248b80a625b6fe1d927f3
 */

static void destroy_l2_mapping(PhysPageEntry *lp, unsigned level)

{

    unsigned i;

    PhysPageEntry *p = lp->u.node;



    if (!p) {

        return;

    }



    for (i = 0; i < L2_SIZE; ++i) {

        if (level > 0) {

            destroy_l2_mapping(&p[i], level - 1);

        } else {

            destroy_page_desc(p[i].u.leaf);

        }

    }

    g_free(p);

    lp->u.node = NULL;

}
