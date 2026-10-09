/* 
 * Benchmark Sample ID : devign_2762
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5706db1deb061ee9affdcea81e59c4c2cad7c41e
 */

static int no_init_out (HWVoiceOut *hw, struct audsettings *as)

{

    audio_pcm_init_info (&hw->info, as);

    hw->samples = 1024;

    return 0;

}
