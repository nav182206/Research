/* 
 * Benchmark Sample ID : devign_829
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a726d7fd4e0b112b276678ea9da9c9b3097e8b8f
 */

const AVOption *av_opt_find(void *obj, const char *name, const char *unit,

                            int opt_flags, int search_flags)

{

    AVClass *c = *(AVClass**)obj;

    const AVOption *o = NULL;



    if (c->opt_find && search_flags & AV_OPT_SEARCH_CHILDREN &&

        (o = c->opt_find(obj, name, unit, opt_flags, search_flags)))

        return o;



    while (o = av_next_option(obj, o)) {

        if (!strcmp(o->name, name) && (!unit || (o->unit && !strcmp(o->unit, unit))) &&

            (o->flags & opt_flags) == opt_flags)

            return o;

    }

    return NULL;

}
