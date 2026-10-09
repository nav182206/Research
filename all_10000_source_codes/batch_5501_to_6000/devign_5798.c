/* 
 * Benchmark Sample ID : devign_5798
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=56c4bfb3f07f3107894c00281276aea4f5e8834d
 */

static int dump_iterate(DumpState *s)

{

    RAMBlock *block;

    int64_t size;

    int ret;



    while (1) {

        block = s->block;



        size = block->length;

        if (s->has_filter) {

            size -= s->start;

            if (s->begin + s->length < block->offset + block->length) {

                size -= block->offset + block->length - (s->begin + s->length);

            }

        }

        ret = write_memory(s, block, s->start, size);

        if (ret == -1) {

            return ret;

        }



        ret = get_next_block(s, block);

        if (ret == 1) {

            dump_completed(s);

            return 0;

        }

    }

}
