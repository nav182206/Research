/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1871
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=db39fcf1f690b02d612e2bfc00980700887abe03
 */

static CharDriverState *chr_open(const char *subtype,

    void (*set_fe_open)(struct CharDriverState *, int))



{

    CharDriverState *chr;

    SpiceCharDriver *s;



    chr = g_malloc0(sizeof(CharDriverState));

    s = g_malloc0(sizeof(SpiceCharDriver));

    s->chr = chr;

    s->active = false;

    s->sin.subtype = g_strdup(subtype);

    chr->opaque = s;

    chr->chr_write = spice_chr_write;

    chr->chr_add_watch = spice_chr_add_watch;

    chr->chr_close = spice_chr_close;

    chr->chr_set_fe_open = set_fe_open;

    chr->explicit_be_open = true;

    chr->chr_fe_event = spice_chr_fe_event;



    QLIST_INSERT_HEAD(&spice_chars, s, next);



    return chr;

}
