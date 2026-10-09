/* 
 * Benchmark Sample ID : devign_2803
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7bdfd907e7072e380f325e735d99677df53f00ec
 */

static void wav_capture_destroy (void *opaque)

{

    WAVState *wav = opaque;



    AUD_del_capture (wav->cap, wav);


}
