/* 
 * Benchmark Sample ID : devign_5129
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0d9acba8fddbf970c7353083e6a60b47017ce3e4
 */

static void audio_init(qemu_irq *pic)

{

    struct soundhw *c;

    int audio_enabled = 0;



    for (c = soundhw; !audio_enabled && c->name; ++c) {

        audio_enabled = c->enabled;

    }



    if (audio_enabled) {

        AudioState *s;



        s = AUD_init();

        if (s) {

            for (c = soundhw; c->name; ++c) {

                if (c->enabled) {

                    if (c->isa) {

                        c->init.init_isa(s, pic);

                    }

                }

            }

        }

    }

}
