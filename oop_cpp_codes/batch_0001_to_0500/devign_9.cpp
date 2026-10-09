/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=636ced8e1dc8248a1353b416240b93d70ad03edb
 */

void assert_avoptions(AVDictionary *m)

{

    AVDictionaryEntry *t;

    if ((t = av_dict_get(m, "", NULL, AV_DICT_IGNORE_SUFFIX))) {

        av_log(NULL, AV_LOG_FATAL, "Option %s not found.\n", t->key);

        exit(1);

    }

}
