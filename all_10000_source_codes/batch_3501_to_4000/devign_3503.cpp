/* 
 * Benchmark Sample ID : devign_3503
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5bb95e41868b461f37159efb48908828ebd7ab36
 */

void do_smbios_option(const char *optarg)

{

#ifdef TARGET_I386

    if (smbios_entry_add(optarg) < 0) {

        fprintf(stderr, "Wrong smbios provided\n");

        exit(1);

    }

#endif

}
