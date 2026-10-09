/* 
 * Benchmark Sample ID : devign_7985
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=245f7b51c0ea04fb2224b1127430a096c91aee70
 */

static int tight_palette_insert(QDict *palette, uint32_t rgb, int bpp, int max)

{

    uint8_t key[6];

    int idx = qdict_size(palette);

    bool present;



    tight_palette_rgb2buf(rgb, bpp, key);

    present = qdict_haskey(palette, (char *)key);

    if (idx >= max && !present) {

        return 0;

    }

    if (!present) {

        qdict_put(palette, (char *)key, qint_from_int(idx));

    }

    return qdict_size(palette);

}
