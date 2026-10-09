/* 
 * Benchmark Sample ID : devign_5298
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=15fa08f8451babc88d733bd411d4c94976f9d0f8
 */

void tcg_op_remove(TCGContext *s, TCGOp *op)

{

    int next = op->next;

    int prev = op->prev;



    /* We should never attempt to remove the list terminator.  */

    tcg_debug_assert(op != &s->gen_op_buf[0]);



    s->gen_op_buf[next].prev = prev;

    s->gen_op_buf[prev].next = next;



    memset(op, 0, sizeof(*op));



#ifdef CONFIG_PROFILER

    atomic_set(&s->prof.del_op_count, s->prof.del_op_count + 1);

#endif

}
