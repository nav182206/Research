/* 
 * Benchmark Sample ID : devign_2016
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ea9ebc2ce69198f7aca4b43652824c5d621ac978
 */

static void qpa_fini_in (HWVoiceIn *hw)

{

    void *ret;

    PAVoiceIn *pa = (PAVoiceIn *) hw;



    audio_pt_lock (&pa->pt, AUDIO_FUNC);

    pa->done = 1;

    audio_pt_unlock_and_signal (&pa->pt, AUDIO_FUNC);

    audio_pt_join (&pa->pt, &ret, AUDIO_FUNC);



    if (pa->s) {

        pa_simple_free (pa->s);

        pa->s = NULL;

    }



    audio_pt_fini (&pa->pt, AUDIO_FUNC);

    g_free (pa->pcm_buf);

    pa->pcm_buf = NULL;

}
