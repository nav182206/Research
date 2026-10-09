/* 
 * Benchmark Sample ID : devign_310
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=843e72ea5542845a0a9fed743517c14a92279885
 */

static int mkv_check_tag(AVDictionary *m)

{

    AVDictionaryEntry *t = NULL;



    while ((t = av_dict_get(m, "", t, AV_DICT_IGNORE_SUFFIX)))

        if (av_strcasecmp(t->key, "title") && av_strcasecmp(t->key, "stereo_mode"))

            return 1;



    return 0;

}
