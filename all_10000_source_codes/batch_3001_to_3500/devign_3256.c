/* 
 * Benchmark Sample ID : devign_3256
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=70556264a89a268efba1d7e8e341adcdd7881eb4
 */

bool qvirtio_wait_queue_isr(const QVirtioBus *bus, QVirtioDevice *d,

                                            QVirtQueue *vq, uint64_t timeout)

{

    do {

        clock_step(100);

        if (bus->get_queue_isr_status(d, vq)) {

            break; /* It has ended */

        }

    } while (--timeout);



    return timeout != 0;

}
