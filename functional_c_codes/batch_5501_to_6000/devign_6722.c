/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6722
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=68d553587c0aa271c3eb2902921b503740d775b6
 */

static inline int put_dwords(uint32_t addr, uint32_t *buf, int num)

{

    int i;



    for(i = 0; i < num; i++, buf++, addr += sizeof(*buf)) {

        uint32_t tmp = cpu_to_le32(*buf);

        cpu_physical_memory_rw(addr,(uint8_t *)&tmp, sizeof(tmp), 1);

    }



    return 1;

}
