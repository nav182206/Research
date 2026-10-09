/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3597
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2828a307232ffceeddec9feb6a87ac660b68b693
 */

static void *oss_audio_init (void)

{

    OSSConf *conf = g_malloc(sizeof(OSSConf));

    *conf = glob_conf;



    if (access(conf->devpath_in, R_OK | W_OK) < 0 ||

        access(conf->devpath_out, R_OK | W_OK) < 0) {


        return NULL;

    }

    return conf;

}
