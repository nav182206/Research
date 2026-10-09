/* 
 * Benchmark Sample ID : devign_3795
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e206ad48333c50373663945746828fc893b50700
 */

ram_addr_t ppc4xx_sdram_adjust(ram_addr_t ram_size, int nr_banks,

                               MemoryRegion ram_memories[],

                               hwaddr ram_bases[],

                               hwaddr ram_sizes[],

                               const unsigned int sdram_bank_sizes[])

{

    ram_addr_t size_left = ram_size;

    ram_addr_t base = 0;

    int i;

    int j;



    for (i = 0; i < nr_banks; i++) {

        for (j = 0; sdram_bank_sizes[j] != 0; j++) {

            unsigned int bank_size = sdram_bank_sizes[j];



            if (bank_size <= size_left) {

                char name[32];

                snprintf(name, sizeof(name), "ppc4xx.sdram%d", i);

                memory_region_allocate_system_memory(&ram_memories[i], NULL,

                                                     name, bank_size);

                ram_bases[i] = base;

                ram_sizes[i] = bank_size;

                base += bank_size;

                size_left -= bank_size;

                break;

            }

        }



        if (!size_left) {

            /* No need to use the remaining banks. */

            break;

        }

    }



    ram_size -= size_left;

    if (size_left)

        printf("Truncating memory to %d MiB to fit SDRAM controller limits.\n",

               (int)(ram_size >> 20));



    return ram_size;

}
