/* 
 * Benchmark Sample ID : devign_9164
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dc523cd348c47372faa7271c9aab2030f94c290d
 */

int qemu_opts_do_parse(QemuOpts *opts, const char *params, const char *firstname)

{

    Error *err = NULL;



    opts_do_parse(opts, params, firstname, false, &err);

    if (err) {

        qerror_report_err(err);

        error_free(err);

        return -1;

    }

    return 0;

}
