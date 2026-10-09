/* 
 * Benchmark Sample ID : devign_1297
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4b635c59b04cae594f49d9aa45d31b3f318def8f
 */

void *qxl_phys2virt(PCIQXLDevice *qxl, QXLPHYSICAL pqxl, int group_id)

{

    uint64_t phys   = le64_to_cpu(pqxl);

    uint32_t slot   = (phys >> (64 -  8)) & 0xff;

    uint64_t offset = phys & 0xffffffffffff;



    switch (group_id) {

    case MEMSLOT_GROUP_HOST:

        return (void *)(intptr_t)offset;

    case MEMSLOT_GROUP_GUEST:

        PANIC_ON(slot >= NUM_MEMSLOTS);

        PANIC_ON(!qxl->guest_slots[slot].active);

        PANIC_ON(offset < qxl->guest_slots[slot].delta);

        offset -= qxl->guest_slots[slot].delta;

        PANIC_ON(offset > qxl->guest_slots[slot].size)

        return qxl->guest_slots[slot].ptr + offset;

    default:

        PANIC_ON(1);

    }

}
