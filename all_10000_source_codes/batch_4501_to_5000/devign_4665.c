/* 
 * Benchmark Sample ID : devign_4665
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=363f8cb9bcd308bd03d28e04ea5f5557dea5d5e8
 */

CharDriverState *qemu_chr_open(const char *label, const char *filename, void (*init)(struct CharDriverState *s))

{

    const char *p;

    CharDriverState *chr;

    QemuOpts *opts;



    if (strstart(filename, "chardev:", &p)) {

        return qemu_chr_find(p);

    }



    opts = qemu_chr_parse_compat(label, filename);

    if (!opts)

        return NULL;



    chr = qemu_chr_open_opts(opts, init);

    if (chr && qemu_opt_get_bool(opts, "mux", 0)) {

        monitor_init(chr, MONITOR_USE_READLINE);

    }


    return chr;

}
