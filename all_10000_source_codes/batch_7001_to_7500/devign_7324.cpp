/* 
 * Benchmark Sample ID : devign_7324
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9db353bc4727d2a184778c110cf4ea0b9d1616cb
 */

static av_cold int avisynth_load_library(void) {

    avs_library = av_mallocz(sizeof(AviSynthLibrary));

    if (!avs_library)

        return AVERROR_UNKNOWN;



    avs_library->library = LoadLibrary(AVISYNTH_LIB);

    if (!avs_library->library)

        goto init_fail;



#define LOAD_AVS_FUNC(name, continue_on_fail) \

{ \

    avs_library->name = (void*)GetProcAddress(avs_library->library, #name); \

    if(!continue_on_fail && !avs_library->name) \

        goto fail; \

}

    LOAD_AVS_FUNC(avs_bit_blt, 0);

    LOAD_AVS_FUNC(avs_clip_get_error, 0);

    LOAD_AVS_FUNC(avs_create_script_environment, 0);

    LOAD_AVS_FUNC(avs_delete_script_environment, 0);

    LOAD_AVS_FUNC(avs_get_audio, 0);

    LOAD_AVS_FUNC(avs_get_error, 1); // New to AviSynth 2.6

    LOAD_AVS_FUNC(avs_get_frame, 0);


    LOAD_AVS_FUNC(avs_get_video_info, 0);

    LOAD_AVS_FUNC(avs_invoke, 0);

    LOAD_AVS_FUNC(avs_release_clip, 0);

    LOAD_AVS_FUNC(avs_release_value, 0);

    LOAD_AVS_FUNC(avs_release_video_frame, 0);

    LOAD_AVS_FUNC(avs_take_clip, 0);

#undef LOAD_AVS_FUNC



    atexit(avisynth_atexit_handler);

    return 0;



fail:

    FreeLibrary(avs_library->library);

init_fail:

    av_freep(&avs_library);

    return AVERROR_UNKNOWN;

}
