/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_678
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=05cc758a3dfc79488d0a8eb7f5830a41871e78d0
 */

static void blkverify_refresh_filename(BlockDriverState *bs, QDict *options)

{

    BDRVBlkverifyState *s = bs->opaque;



    /* bs->file->bs has already been refreshed */

    bdrv_refresh_filename(s->test_file->bs);



    if (bs->file->bs->full_open_options

        && s->test_file->bs->full_open_options)

    {

        QDict *opts = qdict_new();

        qdict_put_str(opts, "driver", "blkverify");



        QINCREF(bs->file->bs->full_open_options);

        qdict_put(opts, "raw", bs->file->bs->full_open_options);

        QINCREF(s->test_file->bs->full_open_options);

        qdict_put(opts, "test", s->test_file->bs->full_open_options);



        bs->full_open_options = opts;

    }



    if (bs->file->bs->exact_filename[0]

        && s->test_file->bs->exact_filename[0])

    {

        snprintf(bs->exact_filename, sizeof(bs->exact_filename),

                 "blkverify:%s:%s",

                 bs->file->bs->exact_filename,

                 s->test_file->bs->exact_filename);

    }

}
