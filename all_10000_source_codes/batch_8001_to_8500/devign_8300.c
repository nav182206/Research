/* 
 * Benchmark Sample ID : devign_8300
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=64d7e9a421fea0ac50b44541f5521de455e7cd5d
 */

static void pit_reset(void *opaque)

{

    PITState *pit = opaque;

    PITChannelState *s;

    int i;



    for(i = 0;i < 3; i++) {

        s = &pit->channels[i];

        s->mode = 3;

        s->gate = (i != 2);

        pit_load_count(s, 0);

    }

}
