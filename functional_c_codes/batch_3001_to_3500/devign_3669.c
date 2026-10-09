/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3669
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=375092332eeaa6e47561ce47fd36144cdaf964d0
 */

static ssize_t test_block_write_func(QCryptoBlock *block,

                                     size_t offset,

                                     const uint8_t *buf,

                                     size_t buflen,

                                     Error **errp,

                                     void *opaque)

{

    Buffer *header = opaque;



    g_assert_cmpint(buflen + offset, <=, header->capacity);



    memcpy(header->buffer + offset, buf, buflen);

    header->offset = offset + buflen;



    return buflen;

}
