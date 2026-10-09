/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7988
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e4a3507e86a1ef1453d603031bca27d5ac4cff3c
 */

static ssize_t test_block_init_func(QCryptoBlock *block,

                                    void *opaque,

                                    size_t headerlen,

                                    Error **errp)

{

    Buffer *header = opaque;



    g_assert_cmpint(header->capacity, ==, 0);



    buffer_reserve(header, headerlen);



    return headerlen;

}
