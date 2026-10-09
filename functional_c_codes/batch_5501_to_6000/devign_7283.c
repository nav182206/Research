/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7283
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2662a059aa2affddfbe42e78b11c802cf30a970f
 */

static void dump_sprs (CPUPPCState *env)

{

    ppc_spr_t *spr;

    uint32_t pvr = env->spr[SPR_PVR];

    uint32_t sr, sw, ur, uw;

    int i, j, n;



    printf("* SPRs for PVR=%08x\n", pvr);

    for (i = 0; i < 32; i++) {

        for (j = 0; j < 32; j++) {

            n = (i << 5) | j;

            spr = &env->spr_cb[n];

#if !defined(CONFIG_USER_ONLY)

            sw = spr->oea_write != NULL && spr->oea_write != SPR_NOACCESS;

            sr = spr->oea_read != NULL && spr->oea_read != SPR_NOACCESS;

#else

            sw = 0;

            sr = 0;

#endif

            uw = spr->uea_write != NULL && spr->uea_write != SPR_NOACCESS;

            ur = spr->uea_read != NULL && spr->uea_read != SPR_NOACCESS;

            if (sw || sr || uw || ur) {

                printf("%4d (%03x) %8s s%c%c u%c%c\n",

                       (i << 5) | j, (i << 5) | j, spr->name,

                       sw ? 'w' : '-', sr ? 'r' : '-',

                       uw ? 'w' : '-', ur ? 'r' : '-');

            }

        }

    }

    fflush(stdout);

    fflush(stderr);

}
