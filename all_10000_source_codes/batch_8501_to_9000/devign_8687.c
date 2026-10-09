/* 
 * Benchmark Sample ID : devign_8687
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4d73cd3b3f55fcff433ce64b125b7adb8aaece29
 */

static int drive_add(const char *file, const char *fmt, ...)

{

    va_list ap;

    int index = drive_opt_get_free_idx();



    if (nb_drives_opt >= MAX_DRIVES || index == -1) {

        fprintf(stderr, "qemu: too many drives\n");

        exit(1);

    }



    drives_opt[index].file = file;

    va_start(ap, fmt);

    vsnprintf(drives_opt[index].opt,

              sizeof(drives_opt[0].opt), fmt, ap);

    va_end(ap);



    nb_drives_opt++;

    return index;

}
