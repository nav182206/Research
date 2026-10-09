/* 
 * Benchmark Sample ID : devign_7040
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8297be80f7cf71e09617669a8bd8b2836dcfd4c3
 */

int gtod_load(QEMUFile *f, void *opaque, int version_id)

{

    uint64_t tod_low;

    uint8_t tod_high;

    int r;



    if (qemu_get_byte(f) == S390_TOD_CLOCK_VALUE_MISSING) {

        fprintf(stderr, "WARNING: Guest clock was not migrated. This could "

                        "cause the guest to hang.\n");

        return 0;

    }



    tod_high = qemu_get_byte(f);

    tod_low = qemu_get_be64(f);



    r = s390_set_clock(&tod_high, &tod_low);

    if (r) {

        fprintf(stderr, "WARNING: Unable to set guest clock value. "

                        "s390_get_clock returned error %d. This could cause "

                        "the guest to hang.\n", r);

    }



    return 0;

}
