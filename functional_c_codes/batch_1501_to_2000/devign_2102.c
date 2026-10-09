/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2102
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b40acf99bef69fa8ab0f9092ff162fde945eec12
 */

void portio_list_del(PortioList *piolist)

{

    MemoryRegion *mr, *alias;

    unsigned i;



    for (i = 0; i < piolist->nr; ++i) {

        mr = piolist->regions[i];

        alias = piolist->aliases[i];

        memory_region_del_subregion(piolist->address_space, alias);

        memory_region_destroy(alias);

        memory_region_destroy(mr);

        g_free((MemoryRegionOps *)mr->ops);

        g_free(mr);

        g_free(alias);

        piolist->regions[i] = NULL;

        piolist->aliases[i] = NULL;

    }

}
