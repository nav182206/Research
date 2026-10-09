/* 
 * Benchmark Sample ID : devign_9577
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bdb5ee3064d5ae786b0bcb6cf6ff4e3554a72990
 */

int rom_copy(uint8_t *dest, target_phys_addr_t addr, size_t size)

{

    target_phys_addr_t end = addr + size;

    uint8_t *s, *d = dest;

    size_t l = 0;

    Rom *rom;



    QTAILQ_FOREACH(rom, &roms, next) {

        if (rom->fw_file) {

            continue;

        }

        if (rom->addr + rom->romsize < addr)

            continue;

        if (rom->addr > end)

            break;

        if (!rom->data)

            continue;



        d = dest + (rom->addr - addr);

        s = rom->data;

        l = rom->romsize;



        if (rom->addr < addr) {

            d = dest;

            s += (addr - rom->addr);

            l -= (addr - rom->addr);

        }

        if ((d + l) > (dest + size)) {

            l = dest - d;

        }



        memcpy(d, s, l);

    }



    return (d + l) - dest;

}
