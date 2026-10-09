/* 
 * Benchmark Sample ID : devign_8444
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9a3501c33a1f88350c935785dbf5435e9ffabe6
 */

int av_opt_set_dict(void *obj, AVDictionary **options)
{
    AVDictionaryEntry *t = NULL;
    AVDictionary    *tmp = NULL;
    int ret = 0;
    while ((t = av_dict_get(*options, "", t, AV_DICT_IGNORE_SUFFIX))) {
        ret = av_opt_set(obj, t->key, t->value, 0);
        if (ret == AVERROR_OPTION_NOT_FOUND)
            av_dict_set(&tmp, t->key, t->value, 0);
        else if (ret < 0) {
            av_log(obj, AV_LOG_ERROR, "Error setting option %s to value %s.\n", t->key, t->value);
            break;
        }
        ret = 0;
    }
    av_dict_free(options);
    *options = tmp;
    return ret;
}
