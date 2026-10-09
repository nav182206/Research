/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6961
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9ef91a677110ec200d7b2904fc4bcae5a77329ad
 */

static void aio_signal_handler(int signum)

{

    if (posix_aio_state) {

        char byte = 0;



        write(posix_aio_state->wfd, &byte, sizeof(byte));

    }



    qemu_service_io();

}
