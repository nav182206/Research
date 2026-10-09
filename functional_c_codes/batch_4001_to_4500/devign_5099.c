/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5099
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2f9606b3736c3be4dbd606c46525c7b770ced119
 */

static void buffer_reserve(Buffer *buffer, size_t len)

{

    if ((buffer->capacity - buffer->offset) < len) {

	buffer->capacity += (len + 1024);

	buffer->buffer = qemu_realloc(buffer->buffer, buffer->capacity);

	if (buffer->buffer == NULL) {

	    fprintf(stderr, "vnc: out of memory\n");

	    exit(1);

	}

    }

}
