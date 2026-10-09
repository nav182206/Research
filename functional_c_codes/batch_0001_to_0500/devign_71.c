/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_71
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1e37d05904e300a0bfc8e3240e24ecc83d54c2e3
 */

static int raw_create(const char *filename, QEMUOptionParameter *options)

{

    int fd;

    int64_t total_size = 0;



    /* Read out options */

    while (options && options->name) {

        if (!strcmp(options->name, BLOCK_OPT_SIZE)) {

            total_size = options->value.n / 512;

        }

        options++;

    }



    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY,

              0644);

    if (fd < 0)

        return -EIO;

    ftruncate(fd, total_size * 512);

    close(fd);

    return 0;

}
