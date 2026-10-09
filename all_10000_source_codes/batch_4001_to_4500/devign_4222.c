/* 
 * Benchmark Sample ID : devign_4222
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=da98c8eb4c35225049cad8cf767647eb39788b5d
 */

void pc_cmos_set_s3_resume(void *opaque, int irq, int level)

{

    ISADevice *s = opaque;



    if (level) {

        rtc_set_memory(s, 0xF, 0xFE);

    }

}
