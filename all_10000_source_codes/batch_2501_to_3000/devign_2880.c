/* 
 * Benchmark Sample ID : devign_2880
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=758e8e38eb582e3dc87fd55a1d234c25108a7b7f
 */

static V9fsFidState *lookup_fid(V9fsState *s, int32_t fid)

{

    V9fsFidState *f;



    for (f = s->fid_list; f; f = f->next) {

        if (f->fid == fid) {

            v9fs_do_setuid(s, f->uid);

            return f;

        }

    }



    return NULL;

}
