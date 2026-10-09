/* 
 * Benchmark Sample ID : devign_5828
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c2cba0ffe495b60c4cc58080281e99c7a6580d4b
 */

void *address_space_map(AddressSpace *as,

                        hwaddr addr,

                        hwaddr *plen,

                        bool is_write)

{

    hwaddr len = *plen;

    hwaddr done = 0;

    hwaddr l, xlat, base;

    MemoryRegion *mr, *this_mr;

    ram_addr_t raddr;



    if (len == 0) {

        return NULL;

    }



    l = len;

    mr = address_space_translate(as, addr, &xlat, &l, is_write);

    if (!memory_access_is_direct(mr, is_write)) {

        if (bounce.buffer) {

            return NULL;

        }

        /* Avoid unbounded allocations */

        l = MIN(l, TARGET_PAGE_SIZE);

        bounce.buffer = qemu_memalign(TARGET_PAGE_SIZE, l);

        bounce.addr = addr;

        bounce.len = l;



        memory_region_ref(mr);

        bounce.mr = mr;

        if (!is_write) {

            address_space_read(as, addr, bounce.buffer, l);

        }



        *plen = l;

        return bounce.buffer;

    }



    base = xlat;

    raddr = memory_region_get_ram_addr(mr);



    for (;;) {

        len -= l;

        addr += l;

        done += l;

        if (len == 0) {

            break;

        }



        l = len;

        this_mr = address_space_translate(as, addr, &xlat, &l, is_write);

        if (this_mr != mr || xlat != base + done) {

            break;

        }

    }



    memory_region_ref(mr);

    *plen = done;

    return qemu_ram_ptr_length(raddr + base, plen);

}
