/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_864
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d6309c170eb99950c9f1d881a5ff7163ae28d353
 */

static void test_acpi_piix4_tcg_cphp(void)

{

    test_data data;



    memset(&data, 0, sizeof(data));

    data.machine = MACHINE_PC;

    data.variant = ".cphp";

    test_acpi_one("-smp 2,cores=3,sockets=2,maxcpus=6",

                  &data);

    free_test_data(&data);

}
