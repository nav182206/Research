/* 
 * Benchmark Sample ID : devign_5502
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3be28969b797b27d7f7f806827e9898e4ee08f0
 */

static int do_compress_ram_page(CompressParam *param)

{

    int bytes_sent, blen;

    uint8_t *p;

    RAMBlock *block = param->block;

    ram_addr_t offset = param->offset;



    p = block->host + (offset & TARGET_PAGE_MASK);



    bytes_sent = save_page_header(param->file, block, offset |

                                  RAM_SAVE_FLAG_COMPRESS_PAGE);

    blen = qemu_put_compression_data(param->file, p, TARGET_PAGE_SIZE,

                                     migrate_compress_level());

    bytes_sent += blen;



    return bytes_sent;

}
