/* 
 * Benchmark Sample ID : devign_9399
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0be839a2701369f669532ea5884c15bead1c6e08
 */

static inline void *host_from_stream_offset(QEMUFile *f,

                                            ram_addr_t offset,

                                            int flags)

{

    static RAMBlock *block = NULL;

    char id[256];

    uint8_t len;



    if (flags & RAM_SAVE_FLAG_CONTINUE) {

        if (!block) {

            error_report("Ack, bad migration stream!");

            return NULL;

        }



        return memory_region_get_ram_ptr(block->mr) + offset;

    }



    len = qemu_get_byte(f);

    qemu_get_buffer(f, (uint8_t *)id, len);

    id[len] = 0;



    QTAILQ_FOREACH(block, &ram_list.blocks, next) {

        if (!strncmp(id, block->idstr, sizeof(id)))

            return memory_region_get_ram_ptr(block->mr) + offset;

    }



    error_report("Can't find block %s!", id);

    return NULL;

}
