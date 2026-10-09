/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7602
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8409dc884a201bf74b30a9d232b6bbdd00cb7e2b
 */

void serial_exit_core(SerialState *s)
{
    qemu_chr_fe_deinit(&s->chr);
    qemu_unregister_reset(serial_reset, s);
}
