/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1324
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0f5cb2989f33059a70e8da335b62af5f27fabbe2
 */

static void rtce_init(VIOsPAPRDevice *dev)

{

    size_t size = (dev->rtce_window_size >> SPAPR_VIO_TCE_PAGE_SHIFT)

        * sizeof(VIOsPAPR_RTCE);



    if (size) {

        dev->rtce_table = g_malloc0(size);

    }

}
