/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1742
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=94fb0909645de18481cc726ee0ec9b5afa861394
 */

static int ram_decompress_open(RamDecompressState *s, QEMUFile *f)

{

    int ret;

    memset(s, 0, sizeof(*s));

    s->f = f;

    ret = inflateInit(&s->zstream);

    if (ret != Z_OK)

        return -1;

    return 0;

}
