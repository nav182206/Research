/* 
 * Benchmark Sample ID : devign_7601
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=70556264a89a268efba1d7e8e341adcdd7881eb4
 */

bool qvirtio_wait_config_isr(const QVirtioBus *bus, QVirtioDevice *d,

                                                            uint64_t timeout)

{

    do {

        clock_step(100);

        if (bus->get_config_isr_status(d)) {

            break; /* It has ended */

        }

    } while (--timeout);



    return timeout != 0;

}
