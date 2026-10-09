/* 
 * Benchmark Sample ID : devign_2496
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=de08c606f9ddafe647b6843e2b10a6d6030b0fc0
 */

static int bdrv_snapshot_find(BlockDriverState *bs, QEMUSnapshotInfo *sn_info,

                              const char *name)

{

    QEMUSnapshotInfo *sn_tab, *sn;

    int nb_sns, i, ret;



    ret = -ENOENT;

    nb_sns = bdrv_snapshot_list(bs, &sn_tab);

    if (nb_sns < 0)

        return ret;

    for(i = 0; i < nb_sns; i++) {

        sn = &sn_tab[i];

        if (!strcmp(sn->id_str, name) || !strcmp(sn->name, name)) {

            *sn_info = *sn;

            ret = 0;

            break;

        }

    }

    g_free(sn_tab);

    return ret;

}
