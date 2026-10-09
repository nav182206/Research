/* 
 * Benchmark Sample ID : devign_69
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a005b3ef50439b5bc6b2eb0b5bda8e8c7c2368bf
 */

int xics_alloc_block(XICSState *icp, int src, int num, bool lsi, bool align)

{

    int i, first = -1;

    ICSState *ics = &icp->ics[src];



    assert(src == 0);

    /*

     * MSIMesage::data is used for storing VIRQ so

     * it has to be aligned to num to support multiple

     * MSI vectors. MSI-X is not affected by this.

     * The hint is used for the first IRQ, the rest should

     * be allocated continuously.

     */

    if (align) {

        assert((num == 1) || (num == 2) || (num == 4) ||

               (num == 8) || (num == 16) || (num == 32));

        first = ics_find_free_block(ics, num, num);

    } else {

        first = ics_find_free_block(ics, num, 1);

    }



    if (first >= 0) {

        for (i = first; i < first + num; ++i) {

            ics_set_irq_type(ics, i, lsi);

        }

    }

    first += ics->offset;



    trace_xics_alloc_block(src, first, num, lsi, align);



    return first;

}
