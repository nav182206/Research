/* 
 * Benchmark Sample ID : devign_7701
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=64d7e9a421fea0ac50b44541f5521de455e7cd5d
 */

int pit_get_initial_count(PITState *pit, int channel)

{

    PITChannelState *s = &pit->channels[channel];

    return s->count;

}
