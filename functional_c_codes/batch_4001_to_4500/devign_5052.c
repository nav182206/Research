/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5052
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2f9606b3736c3be4dbd606c46525c7b770ced119
 */

static void buffer_append(Buffer *buffer, const void *data, size_t len)

{

    memcpy(buffer->buffer + buffer->offset, data, len);

    buffer->offset += len;

}
