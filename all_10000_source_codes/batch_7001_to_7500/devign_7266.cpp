/* 
 * Benchmark Sample ID : devign_7266
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d00b261816872d3e48adca584fca80ca21985f3b
 */

static void do_wav_capture(Monitor *mon, const QDict *qdict)

{

    const char *path = qdict_get_str(qdict, "path");

    int has_freq = qdict_haskey(qdict, "freq");

    int freq = qdict_get_try_int(qdict, "freq", -1);

    int has_bits = qdict_haskey(qdict, "bits");

    int bits = qdict_get_try_int(qdict, "bits", -1);

    int has_channels = qdict_haskey(qdict, "nchannels");

    int nchannels = qdict_get_try_int(qdict, "nchannels", -1);

    CaptureState *s;



    s = qemu_mallocz (sizeof (*s));



    freq = has_freq ? freq : 44100;

    bits = has_bits ? bits : 16;

    nchannels = has_channels ? nchannels : 2;



    if (wav_start_capture (s, path, freq, bits, nchannels)) {

        monitor_printf(mon, "Faied to add wave capture\n");

        qemu_free (s);

    }

    QLIST_INSERT_HEAD (&capture_head, s, entries);

}
