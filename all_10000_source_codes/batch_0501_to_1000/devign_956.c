/* 
 * Benchmark Sample ID : devign_956
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9ef91a677110ec200d7b2904fc4bcae5a77329ad
 */

int qemu_paio_error(struct qemu_paiocb *aiocb)

{

    ssize_t ret = qemu_paio_return(aiocb);



    if (ret < 0)

        ret = -ret;

    else

        ret = 0;



    return ret;

}
