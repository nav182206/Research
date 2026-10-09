/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3909
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2bf3aa85f08186b8162b76e7e8efe5b5a44306a6
 */

static int save_zero_page(RAMState *rs, RAMBlock *block, ram_addr_t offset,

                          uint8_t *p)

{

    int pages = -1;



    if (is_zero_range(p, TARGET_PAGE_SIZE)) {

        rs->zero_pages++;

        rs->bytes_transferred +=

            save_page_header(rs, block, offset | RAM_SAVE_FLAG_COMPRESS);

        qemu_put_byte(rs->f, 0);

        rs->bytes_transferred += 1;

        pages = 1;

    }



    return pages;

}
