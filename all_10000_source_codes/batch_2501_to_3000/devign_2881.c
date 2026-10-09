/* 
 * Benchmark Sample ID : devign_2881
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a89f364ae8740dfc31b321eed9ee454e996dc3c1
 */

static int hda_audio_post_load(void *opaque, int version)

{

    HDAAudioState *a = opaque;

    HDAAudioStream *st;

    int i;



    dprint(a, 1, "%s\n", __FUNCTION__);

    if (version == 1) {

        /* assume running_compat[] is for output streams */

        for (i = 0; i < ARRAY_SIZE(a->running_compat); i++)

            a->running_real[16 + i] = a->running_compat[i];

    }



    for (i = 0; i < ARRAY_SIZE(a->st); i++) {

        st = a->st + i;

        if (st->node == NULL)

            continue;

        hda_codec_parse_fmt(st->format, &st->as);

        hda_audio_setup(st);

        hda_audio_set_amp(st);

        hda_audio_set_running(st, a->running_real[st->output * 16 + st->stream]);

    }

    return 0;

}
