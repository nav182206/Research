/* 
 * Benchmark Sample ID : devign_9930
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5706db1deb061ee9affdcea81e59c4c2cad7c41e
 */

static int line_in_init (HWVoiceIn *hw, struct audsettings *as)

{

    SpiceVoiceIn *in = container_of (hw, SpiceVoiceIn, hw);

    struct audsettings settings;



#if SPICE_INTERFACE_RECORD_MAJOR > 2 || SPICE_INTERFACE_RECORD_MINOR >= 3

    settings.freq       = spice_server_get_best_record_rate(NULL);

#else

    settings.freq       = SPICE_INTERFACE_RECORD_FREQ;

#endif

    settings.nchannels  = SPICE_INTERFACE_RECORD_CHAN;

    settings.fmt        = AUD_FMT_S16;

    settings.endianness = AUDIO_HOST_ENDIANNESS;



    audio_pcm_init_info (&hw->info, &settings);

    hw->samples = LINE_IN_SAMPLES;

    in->active = 0;



    in->sin.base.sif = &record_sif.base;

    qemu_spice_add_interface (&in->sin.base);

#if SPICE_INTERFACE_RECORD_MAJOR > 2 || SPICE_INTERFACE_RECORD_MINOR >= 3

    spice_server_set_record_rate(&in->sin, settings.freq);

#endif

    return 0;

}
