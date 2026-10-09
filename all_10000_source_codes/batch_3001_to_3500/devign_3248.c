/* 
 * Benchmark Sample ID : devign_3248
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f460be435f8750d5d1484d3d8b9e5b2c334f0e20
 */

static void acpi_dsdt_add_cpus(Aml *scope, int smp_cpus)

{

    uint16_t i;



    for (i = 0; i < smp_cpus; i++) {

        Aml *dev = aml_device("C%03x", i);

        aml_append(dev, aml_name_decl("_HID", aml_string("ACPI0007")));

        aml_append(dev, aml_name_decl("_UID", aml_int(i)));

        aml_append(scope, dev);

    }

}
