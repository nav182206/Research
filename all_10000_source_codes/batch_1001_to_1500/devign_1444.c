/* 
 * Benchmark Sample ID : devign_1444
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void check_reserved_space (target_phys_addr_t *start,

                                  target_phys_addr_t *length)

{

    target_phys_addr_t begin = *start;

    target_phys_addr_t end = *start + *length;



    if (end >= 0x1e000000LL && end < 0x1f100000LL)

        end = 0x1e000000LL;

    if (begin >= 0x1e000000LL && begin < 0x1f100000LL)

        begin = 0x1f100000LL;

    if (end >= 0x1fc00000LL && end < 0x1fd00000LL)

        end = 0x1fc00000LL;

    if (begin >= 0x1fc00000LL && begin < 0x1fd00000LL)

        begin = 0x1fd00000LL;

    /* XXX: This is broken when a reserved range splits the requested range */

    if (end >= 0x1f100000LL && begin < 0x1e000000LL)

        end = 0x1e000000LL;

    if (end >= 0x1fd00000LL && begin < 0x1fc00000LL)

        end = 0x1fc00000LL;



    *start = begin;

    *length = end - begin;

}
