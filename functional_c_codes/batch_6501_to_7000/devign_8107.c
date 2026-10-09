/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8107
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=375092332eeaa6e47561ce47fd36144cdaf964d0
 */

static ssize_t test_block_init_func(QCryptoBlock *block,

                                    size_t headerlen,

                                    Error **errp,

                                    void *opaque)

{

    Buffer *header = opaque;



    g_assert_cmpint(header->capacity, ==, 0);



    buffer_reserve(header, headerlen);



    return headerlen;

}
