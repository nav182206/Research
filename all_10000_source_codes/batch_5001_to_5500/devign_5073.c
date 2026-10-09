/* 
 * Benchmark Sample ID : devign_5073
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=880a7578381d1c7ed4d41c7599ae3cc06567a824
 */

int use_gdb_syscalls(void)

{

    if (gdb_syscall_mode == GDB_SYS_UNKNOWN) {

        gdb_syscall_mode = (gdb_syscall_state ? GDB_SYS_ENABLED

                                              : GDB_SYS_DISABLED);

    }

    return gdb_syscall_mode == GDB_SYS_ENABLED;

}
