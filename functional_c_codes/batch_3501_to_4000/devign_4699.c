/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4699
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3dc6f8693694a649a9c83f1e2746565b47683923
 */

static int ast2500_rambits(AspeedSDMCState *s)

{

    switch (s->ram_size >> 20) {

    case 128:

        return ASPEED_SDMC_AST2500_128MB;

    case 256:

        return ASPEED_SDMC_AST2500_256MB;

    case 512:

        return ASPEED_SDMC_AST2500_512MB;

    case 1024:

        return ASPEED_SDMC_AST2500_1024MB;

    default:

        break;

    }



    /* use a common default */

    error_report("warning: Invalid RAM size 0x%" PRIx64

                 ". Using default 512M", s->ram_size);

    s->ram_size = 512 << 20;

    return ASPEED_SDMC_AST2500_512MB;

}
