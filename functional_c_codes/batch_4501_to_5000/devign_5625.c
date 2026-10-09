/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5625
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=17df768c1e4580f03301d18ea938d3557d441911
 */

int load_image_targphys(const char *filename,

			target_phys_addr_t addr, int max_sz)

{

    int size;



    size = get_image_size(filename);

    if (size > 0)

        rom_add_file_fixed(filename, addr, -1);

    return size;

}
