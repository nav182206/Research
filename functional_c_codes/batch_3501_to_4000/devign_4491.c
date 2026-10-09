/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4491
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5bb95e41868b461f37159efb48908828ebd7ab36
 */

static void smbios_validate_table(void)

{

    if (smbios_type4_count && smbios_type4_count != smp_cpus) {

         fprintf(stderr,

                 "Number of SMBIOS Type 4 tables must match cpu count.\n");

        exit(1);

    }

}
