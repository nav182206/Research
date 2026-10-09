/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_1761
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

void pdu_submit(V9fsPDU *pdu)

{

    Coroutine *co;

    CoroutineEntry *handler;

    V9fsState *s = pdu->s;



    if (pdu->id >= ARRAY_SIZE(pdu_co_handlers) ||

        (pdu_co_handlers[pdu->id] == NULL)) {

        handler = v9fs_op_not_supp;

    } else {

        handler = pdu_co_handlers[pdu->id];

    }



    if (is_ro_export(&s->ctx) && !is_read_only_op(pdu)) {

        handler = v9fs_fs_ro;

    }

    co = qemu_coroutine_create(handler);

    qemu_coroutine_enter(co, pdu);

}
