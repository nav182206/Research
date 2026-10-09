/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7473
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ab3ad07f89c7f9e03c17c98e1d1a02dbf61c605c
 */

int e820_add_entry(uint64_t address, uint64_t length, uint32_t type)

{

    int index = le32_to_cpu(e820_reserve.count);

    struct e820_entry *entry;



    if (type != E820_RAM) {

        /* old FW_CFG_E820_TABLE entry -- reservations only */

        if (index >= E820_NR_ENTRIES) {

            return -EBUSY;

        }

        entry = &e820_reserve.entry[index++];



        entry->address = cpu_to_le64(address);

        entry->length = cpu_to_le64(length);

        entry->type = cpu_to_le32(type);



        e820_reserve.count = cpu_to_le32(index);

    }



    /* new "etc/e820" file -- include ram too */

    e820_table = g_realloc(e820_table,

                           sizeof(struct e820_entry) * (e820_entries+1));

    e820_table[e820_entries].address = cpu_to_le64(address);

    e820_table[e820_entries].length = cpu_to_le64(length);

    e820_table[e820_entries].type = cpu_to_le32(type);

    e820_entries++;



    return e820_entries;

}
