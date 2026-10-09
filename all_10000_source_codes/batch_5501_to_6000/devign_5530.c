/* 
 * Benchmark Sample ID : devign_5530
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9ef91a677110ec200d7b2904fc4bcae5a77329ad
 */

int qemu_paio_ioctl(struct qemu_paiocb *aiocb)

{

    return qemu_paio_submit(aiocb, QEMU_PAIO_IOCTL);

}
