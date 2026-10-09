/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4520
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=403e633126b7a781ecd48a29e3355770d46bbf1a
 */

int qemu_thread_is_self(QemuThread *thread)

{

    QemuThread *this_thread = TlsGetValue(qemu_thread_tls_index);

    return this_thread->thread == thread->thread;

}
