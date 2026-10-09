/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4023
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6744cbab8cd63b7ce72b3eee4f0055007acf0798
 */

static int qcow2_probe(const uint8_t *buf, int buf_size, const char *filename)

{

    const QCowHeader *cow_header = (const void *)buf;



    if (buf_size >= sizeof(QCowHeader) &&

        be32_to_cpu(cow_header->magic) == QCOW_MAGIC &&

        be32_to_cpu(cow_header->version) >= QCOW_VERSION)

        return 100;

    else

        return 0;

}
