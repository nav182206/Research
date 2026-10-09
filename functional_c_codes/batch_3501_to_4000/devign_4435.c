/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4435
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static int vmstate_size(void *opaque, VMStateField *field)

{

    int size = field->size;



    if (field->flags & VMS_VBUFFER) {

        size = *(int32_t *)(opaque+field->size_offset);

        if (field->flags & VMS_MULTIPLY) {

            size *= field->size;

        }

    }



    return size;

}
