/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6106
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=34fb84a97d112d85091369e9ef9ce177a05644e9
 */

av_cold int ff_dcaadpcm_init(DCAADPCMEncContext *s)
{
    if (!s)
        return -1;
    s->private_data = av_malloc(sizeof(premultiplied_coeffs) * DCA_ADPCM_VQCODEBOOK_SZ);
    precalc(s->private_data);
    return 0;
}
