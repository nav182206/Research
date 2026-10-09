/* 
 * Benchmark Sample ID : devign_2394
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=32bafa8fdd098d52fbf1102d5a5e48d29398c0aa
 */

static void qemu_chr_parse_ringbuf(QemuOpts *opts, ChardevBackend *backend,

                                   Error **errp)

{

    int val;

    ChardevRingbuf *ringbuf;



    ringbuf = backend->u.ringbuf = g_new0(ChardevRingbuf, 1);

    qemu_chr_parse_common(opts, qapi_ChardevRingbuf_base(ringbuf));



    val = qemu_opt_get_size(opts, "size", 0);

    if (val != 0) {

        ringbuf->has_size = true;

        ringbuf->size = val;

    }

}
