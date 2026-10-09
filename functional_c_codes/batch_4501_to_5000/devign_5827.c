/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5827
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aded6539d983280212e08d09f14157b1cb4d58cc
 */

static int stdio_put_buffer(void *opaque, const uint8_t *buf, int64_t pos,

                            int size)

{

    QEMUFileStdio *s = opaque;

    return fwrite(buf, 1, size, s->stdio_file);

}
