/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4708
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c488c7f649106d09df76f697adccbe6e72520b26
 */

static QObject* bdrv_info_stats_bs(BlockDriverState *bs)

{

    QObject *res;

    QDict *dict;



    res = qobject_from_jsonf("{ 'stats': {"

                             "'rd_bytes': %" PRId64 ","

                             "'wr_bytes': %" PRId64 ","

                             "'rd_operations': %" PRId64 ","

                             "'wr_operations': %" PRId64 ","

                             "'wr_highest_offset': %" PRId64 ","

                             "'flush_operations': %" PRId64

                             "} }",

                             bs->nr_bytes[BDRV_ACCT_READ],

                             bs->nr_bytes[BDRV_ACCT_WRITE],

                             bs->nr_ops[BDRV_ACCT_READ],

                             bs->nr_ops[BDRV_ACCT_WRITE],

                             bs->wr_highest_sector *

                             (uint64_t)BDRV_SECTOR_SIZE,

                             bs->nr_ops[BDRV_ACCT_FLUSH]);

    dict  = qobject_to_qdict(res);



    if (*bs->device_name) {

        qdict_put(dict, "device", qstring_from_str(bs->device_name));

    }



    if (bs->file) {

        QObject *parent = bdrv_info_stats_bs(bs->file);

        qdict_put_obj(dict, "parent", parent);

    }



    return res;

}
