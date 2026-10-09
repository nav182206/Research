/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7448
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e3a0abfda71db1fa83be894dcff7c4871b36cc8d
 */

static PageDesc *page_find_alloc(tb_page_addr_t index, int alloc)

{

    PageDesc *pd;

    void **lp;

    int i;



#if defined(CONFIG_USER_ONLY)

    /* We can't use g_malloc because it may recurse into a locked mutex. */

# define ALLOC(P, SIZE)                                 \

    do {                                                \

        P = mmap(NULL, SIZE, PROT_READ | PROT_WRITE,    \

                 MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);   \

    } while (0)

#else

# define ALLOC(P, SIZE) \

    do { P = g_malloc0(SIZE); } while (0)

#endif



    /* Level 1.  Always allocated.  */

    lp = l1_map + ((index >> V_L1_SHIFT) & (V_L1_SIZE - 1));



    /* Level 2..N-1.  */

    for (i = V_L1_SHIFT / V_L2_BITS - 1; i > 0; i--) {

        void **p = *lp;



        if (p == NULL) {

            if (!alloc) {

                return NULL;

            }

            ALLOC(p, sizeof(void *) * V_L2_SIZE);

            *lp = p;

        }



        lp = p + ((index >> (i * V_L2_BITS)) & (V_L2_SIZE - 1));

    }



    pd = *lp;

    if (pd == NULL) {

        if (!alloc) {

            return NULL;

        }

        ALLOC(pd, sizeof(PageDesc) * V_L2_SIZE);

        *lp = pd;

    }



#undef ALLOC



    return pd + (index & (V_L2_SIZE - 1));

}
