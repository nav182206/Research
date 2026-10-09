/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_898
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=64d7e9a421fea0ac50b44541f5521de455e7cd5d
 */

int pit_get_gate(PITState *pit, int channel)

{

    PITChannelState *s = &pit->channels[channel];

    return s->gate;

}
