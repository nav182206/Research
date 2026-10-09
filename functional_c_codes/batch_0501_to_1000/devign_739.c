/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_739
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=880a7578381d1c7ed4d41c7599ae3cc06567a824
 */

void gdb_exit(CPUState *env, int code)

{

  GDBState *s;

  char buf[4];



  s = &gdbserver_state;

  if (gdbserver_fd < 0 || s->fd < 0)

    return;



  snprintf(buf, sizeof(buf), "W%02x", code);

  put_packet(s, buf);

}
