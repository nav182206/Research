/* 
 * Benchmark Sample ID : devign_4530
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3d0f44189178aab3a21a33ecf6a113b9abaea2bc
 */

void gdb_exit(CPUArchState *env, int code)

{

  GDBState *s;

  char buf[4];



  s = gdbserver_state;

  if (!s) {

      return;

  }

#ifdef CONFIG_USER_ONLY

  if (gdbserver_fd < 0 || s->fd < 0) {

      return;

  }

#endif



  snprintf(buf, sizeof(buf), "W%02x", (uint8_t)code);

  put_packet(s, buf);



#ifndef CONFIG_USER_ONLY

  if (s->chr) {

      qemu_chr_delete(s->chr);

  }

#endif

}
