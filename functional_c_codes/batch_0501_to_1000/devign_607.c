/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_607
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c3234c6c037943bd4c2d643a1b8cc35f563dbdb
 */

static void submit_pdu(V9fsState *s, V9fsPDU *pdu)

{

    pdu_handler_t *handler;



    if (debug_9p_pdu) {

        pprint_pdu(pdu);

    }



    BUG_ON(pdu->id >= ARRAY_SIZE(pdu_handlers));



    handler = pdu_handlers[pdu->id];

    BUG_ON(handler == NULL);



    handler(s, pdu);

}
