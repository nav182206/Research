/* 
 * Benchmark Sample ID : devign_2468
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f61eddcb2bb5cbbdd1d911b7e937db9affc29028
 */

static int serial_parse(const char *devname)

{

    static int index = 0;

    char label[32];



    if (strcmp(devname, "none") == 0)

        return 0;

    if (index == MAX_SERIAL_PORTS) {

        fprintf(stderr, "qemu: too many serial ports\n");

        exit(1);

    }

    snprintf(label, sizeof(label), "serial%d", index);

    serial_hds[index] = qemu_chr_new(label, devname, NULL);

    if (!serial_hds[index]) {

        fprintf(stderr, "qemu: could not connect serial device"

                " to character backend '%s'\n", devname);

        return -1;

    }

    index++;

    return 0;

}
