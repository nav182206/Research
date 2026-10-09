/* 
 * Benchmark Sample ID : devign_6372
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1ea879e5580f63414693655fcf0328559cdce138
 */

static int no_init_out (HWVoiceOut *hw, audsettings_t *as)

{

    audio_pcm_init_info (&hw->info, as);

    hw->samples = 1024;

    return 0;

}
