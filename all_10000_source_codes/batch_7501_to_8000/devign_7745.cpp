/* 
 * Benchmark Sample ID : devign_7745
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ad96090a01d848df67d70c5259ed8aa321fa8716
 */

static void do_smbios_option(const char *optarg)

{

    if (smbios_entry_add(optarg) < 0) {

        fprintf(stderr, "Wrong smbios provided\n");

        exit(1);

    }

}
