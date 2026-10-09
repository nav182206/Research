/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4564
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9ef91a677110ec200d7b2904fc4bcae5a77329ad
 */

static int aiocb_needs_copy(struct qemu_paiocb *aiocb)

{

    if (aiocb->aio_flags & QEMU_AIO_SECTOR_ALIGNED) {

        int i;



        for (i = 0; i < aiocb->aio_niov; i++)

            if ((uintptr_t) aiocb->aio_iov[i].iov_base % 512)

                return 1;

    }



    return 0;

}
