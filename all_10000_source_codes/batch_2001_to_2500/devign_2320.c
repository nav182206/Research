/* 
 * Benchmark Sample ID : devign_2320
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bb3e9e1fd7ab62b60780c66d68b2d7bfd8758e61
 */

static int chr_can_read(void *opaque)

{

    SCLPConsole *scon = opaque;



    return SIZE_BUFFER_VT220 - scon->iov_data_len;

}
