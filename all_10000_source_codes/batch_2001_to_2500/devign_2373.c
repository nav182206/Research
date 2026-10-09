/* 
 * Benchmark Sample ID : devign_2373
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=104bf02eb50e080ac9d0de5905f80f9a09730154
 */

static int acpi_checksum(const uint8_t *data, int len)

{

    int sum, i;

    sum = 0;

    for(i = 0; i < len; i++)

        sum += data[i];

    return (-sum) & 0xff;

}
