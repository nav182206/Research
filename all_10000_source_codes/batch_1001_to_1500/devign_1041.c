/* 
 * Benchmark Sample ID : devign_1041
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=04001767728fd4ed8b4f9d2ebbb9f9a8c9a7be0d
 */

static void uninit(struct vf_instance *vf)

{

    free(vf->priv);

}
