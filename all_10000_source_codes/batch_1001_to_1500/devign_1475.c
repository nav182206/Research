/* 
 * Benchmark Sample ID : devign_1475
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=073c2593c9f0aa4445a6fc1b9b24e6e52a8cc2c1
 */

static int alloc_table(VLC *vlc, int size)

{

    int index;

    index = vlc->table_size;

    vlc->table_size += size;

    if (vlc->table_size > vlc->table_allocated) {

        vlc->table_allocated += (1 << vlc->bits);

        vlc->table = av_realloc(vlc->table,

                                sizeof(VLC_TYPE) * 2 * vlc->table_allocated);

        if (!vlc->table)

            return -1;

    }

    return index;

}
