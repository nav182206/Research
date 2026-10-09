/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9699
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4d8d5467cd6e324fb49ae97b9d5dcee3973d9a19
 */

static uint32_t regtype_to_ss(uint8_t type)

{

    if (type & PCI_BASE_ADDRESS_MEM_TYPE_64) {

        return 3;

    }

    if (type == PCI_BASE_ADDRESS_SPACE_IO) {

        return 1;

    }

    return 2;

}
