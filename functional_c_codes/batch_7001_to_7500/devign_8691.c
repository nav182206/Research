/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8691
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=56c4bfb3f07f3107894c00281276aea4f5e8834d
 */

static int get_next_block(DumpState *s, RAMBlock *block)

{

    while (1) {

        block = QTAILQ_NEXT(block, next);

        if (!block) {

            /* no more block */

            return 1;

        }



        s->start = 0;

        s->block = block;

        if (s->has_filter) {

            if (block->offset >= s->begin + s->length ||

                block->offset + block->length <= s->begin) {

                /* This block is out of the range */

                continue;

            }



            if (s->begin > block->offset) {

                s->start = s->begin - block->offset;

            }

        }



        return 0;

    }

}
