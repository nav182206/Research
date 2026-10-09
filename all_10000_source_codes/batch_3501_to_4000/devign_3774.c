/* 
 * Benchmark Sample ID : devign_3774
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9a3b33d2c9f996537b7f1d0246dee2d0120cefb
 */

void acpi_gpe_init(ACPIREGS *ar, uint8_t len)

{

    ar->gpe.len = len;

    ar->gpe.sts = g_malloc0(len / 2);

    ar->gpe.en = g_malloc0(len / 2);

}
