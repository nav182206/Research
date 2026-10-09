/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6826
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=46536235d80a012cc4286b71426cafad0c7f41f0
 */

static int parallels_open(BlockDriverState *bs, int flags)

{

    BDRVParallelsState *s = bs->opaque;

    int i;

    struct parallels_header ph;



    bs->read_only = 1; // no write support yet



    if (bdrv_pread(bs->file, 0, &ph, sizeof(ph)) != sizeof(ph))

        goto fail;



    if (memcmp(ph.magic, HEADER_MAGIC, 16) ||

	(le32_to_cpu(ph.version) != HEADER_VERSION)) {

        goto fail;

    }



    bs->total_sectors = le32_to_cpu(ph.nb_sectors);



    s->tracks = le32_to_cpu(ph.tracks);



    s->catalog_size = le32_to_cpu(ph.catalog_entries);

    s->catalog_bitmap = g_malloc(s->catalog_size * 4);

    if (bdrv_pread(bs->file, 64, s->catalog_bitmap, s->catalog_size * 4) !=

	s->catalog_size * 4)

	goto fail;

    for (i = 0; i < s->catalog_size; i++)

	le32_to_cpus(&s->catalog_bitmap[i]);



    qemu_co_mutex_init(&s->lock);

    return 0;

fail:

    if (s->catalog_bitmap)

	g_free(s->catalog_bitmap);

    return -1;

}
