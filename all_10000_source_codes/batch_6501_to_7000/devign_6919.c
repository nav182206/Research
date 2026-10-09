/* 
 * Benchmark Sample ID : devign_6919
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c31bc98e3bcf52fe1cd4b9b7a70869330eae80ea
 */

static inline void softusb_read_dmem(MilkymistSoftUsbState *s,

        uint32_t offset, uint8_t *buf, uint32_t len)

{

    if (offset + len >= s->dmem_size) {

        error_report("milkymist_softusb: read dmem out of bounds "

                "at offset 0x%x, len %d", offset, len);


        return;

    }



    memcpy(buf, s->dmem_ptr + offset, len);

}
