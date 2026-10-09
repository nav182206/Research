/* 
 * Benchmark Sample ID : devign_4626
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d91ddd25e3a4e5008a2ac16127d51a34fd56bf1
 */

NetQueue *qemu_new_net_queue(void *opaque)

{

    NetQueue *queue;



    queue = g_malloc0(sizeof(NetQueue));



    queue->opaque = opaque;





    QTAILQ_INIT(&queue->packets);



    queue->delivering = 0;



    return queue;

}
