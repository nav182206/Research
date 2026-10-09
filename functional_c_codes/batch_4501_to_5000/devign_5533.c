/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5533
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e494f44c051d7dccc038a603ab22532b87dd1705
 */

static CodeBook unpack_codebook(GetBitContext* gb, unsigned depth,

                                 unsigned size)

{

    unsigned i, j;

    CodeBook cb = { 0 };



    if (!can_safely_read(gb, (uint64_t)size * 34))

        return cb;



    if (size >= INT_MAX / sizeof(MacroBlock))

        return cb;

    cb.blocks = av_malloc(size ? size * sizeof(MacroBlock) : 1);

    if (!cb.blocks)

        return cb;



    cb.depth = depth;

    cb.size = size;

    for (i = 0; i < size; i++) {

        unsigned mask_bits = get_bits(gb, 4);

        unsigned color0 = get_bits(gb, 15);

        unsigned color1 = get_bits(gb, 15);



        for (j = 0; j < 4; j++) {

            if (mask_bits & (1 << j))

                cb.blocks[i].pixels[j] = color1;

            else

                cb.blocks[i].pixels[j] = color0;

        }

    }

    return cb;

}
