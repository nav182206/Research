/* 
 * Benchmark Sample ID : devign_9294
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0d4cc3e715f5794077895345577725539afe81eb
 */

static int vpc_has_zero_init(BlockDriverState *bs)

{

    BDRVVPCState *s = bs->opaque;

    VHDFooter *footer =  (VHDFooter *) s->footer_buf;



    if (cpu_to_be32(footer->type) == VHD_FIXED) {

        return bdrv_has_zero_init(bs->file);

    } else {

        return 1;

    }

}
