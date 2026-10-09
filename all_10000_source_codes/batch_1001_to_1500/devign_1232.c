/* 
 * Benchmark Sample ID : devign_1232
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3d4d16f4dc101e16f643acc44dfffdbaf2a8f01c
 */

static void audio_run_in (AudioState *s)

{

    HWVoiceIn *hw = NULL;



    while ((hw = audio_pcm_hw_find_any_enabled_in (hw))) {

        SWVoiceIn *sw;

        int captured, min;



        captured = hw->pcm_ops->run_in (hw);



        min = audio_pcm_hw_find_min_in (hw);

        hw->total_samples_captured += captured - min;

        hw->ts_helper += captured;



        for (sw = hw->sw_head.lh_first; sw; sw = sw->entries.le_next) {

            sw->total_hw_samples_acquired -= min;



            if (sw->active) {

                int avail;



                avail = audio_get_avail (sw);

                if (avail > 0) {

                    sw->callback.fn (sw->callback.opaque, avail);

                }

            }

        }

    }

}
